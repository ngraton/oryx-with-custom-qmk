# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a QMK custom firmware builder for a ZSA Voyager keyboard. It bridges Oryx's visual layout editor with advanced QMK features by:
1. Fetching layouts from Oryx via GraphQL API
2. Merging them with custom QMK code on the `main` branch
3. Building firmware in Docker via GitHub Actions
4. Producing a `.bin`/`.hex` artifact for flashing with Keymapp

Forked from [poulainpi/oryx-with-custom-qmk](https://github.com/poulainpi/oryx-with-custom-qmk). Layout ID: `QwnaB`.

## Project Goals

The primary goal is adding **custom RGB matrix animations** that aren't possible through Oryx alone. Specifically, creating recolored variants of existing QMK animations using a cyberpunk/neon color palette:
- **Primary:** neon purple, neon yellow
- **Accent:** neon green, neon pink

Custom animations go in `QwnaB/rgb_matrix_user.inc`. Secondary goal is adding other QMK features not supported by Oryx as needed.

## Branch Strategy

- **`main`** — custom QMK source code (what you edit)
- **`oryx`** — auto-synced from Oryx; do not edit directly
- The GitHub Action merges `oryx` into `main` during builds, using whitespace-ignoring merge

## Building Firmware

Builds run via GitHub Actions (`fetch-and-build-layout.yml`), triggered manually with `layout_id` and `layout_geometry` inputs. There is no local build target — the build happens inside a Docker container running QMK CLI.

The workflow:
1. Fetches layout source from `https://oryx.zsa.io/graphql`
2. Merges Oryx changes into the custom branch
3. Updates the `qmk_firmware` submodule to the correct version branch
4. Builds inside Docker: `make zsa/voyager:QwnaB` (firmware v25+) or `make voyager:QwnaB` (older)

To build locally with Docker:
```bash
docker build -t qmk .
docker run --rm -v $(pwd)/qmk_firmware:/qmk_firmware qmk make zsa/voyager:QwnaB
```

## Key Source Files

All custom firmware code lives in `QwnaB/`:

- **`keymap.c`** — Main keymap: 5 layers (Base, Symbols, Media/Nav, Mouse, Text Nav), custom keycodes, chordal hold layout, RGB layer indicators, trackball/mouse handling
- **`config.h`** — Hardware config: chordal hold, trackball CPI/scroll, auto-mouse layer, RGB speed, USB suspend
- **`rules.mk`** — Build flags: enables Oryx, layer lock, pointing device (navigator_trackball), RGB matrix
- **`keymap.json`** — Oryx module declarations (`zsa/oryx`, `zsa/defaults`)
- **`rgb_matrix_user.inc`** — Custom RGB matrix effects (currently empty)

## Architecture Notes

- The `qmk_firmware` directory is a Git submodule pointing to ZSA's QMK fork. The workflow auto-updates it to the version branch matching the Oryx layout.
- The workflow supports multiple geometries: voyager, moonlander (revA/B), ergodox_ez variants, planck_ez. The compile command path changes based on firmware version (v25+ uses `zsa/` prefix).
- Custom keycodes are defined in `keymap.c` via an enum starting after `SAFE_RANGE`. Process record user handles RGB_SLD, drag scroll, and navigator controls.
- Layer 3 is the auto-mouse layer (configured in `config.h` with `POINTING_DEVICE_AUTO_MOUSE_ENABLE`).
