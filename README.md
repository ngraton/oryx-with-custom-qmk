# Voyager Custom Firmware Builder

Custom QMK firmware for my [ZSA Voyager](https://www.zsa.io/voyager), combining [Oryx](https://www.zsa.io/oryx) layout editing with custom QMK features and RGB animations. Built on top of [poulainpi/oryx-with-custom-qmk](https://github.com/poulainpi/oryx-with-custom-qmk) — see the [blog post](https://blog.zsa.io/oryx-custom-qmk-features) for background.

The main addition is custom RGB matrix animations using a cyberpunk/neon color palette (neon purple, neon yellow, neon green, neon pink) — effects that aren’t possible through Oryx alone.

## How it works

Each time you run the GitHub Action, the workflow will:
1. Fetch the latest changes made in Oryx.
2. Merge them with any QMK features you've added in the source code.
3. Build the firmware, incorporating modifications from both Oryx and your custom source code.

## How to use

1. Fork this repository (be sure to **uncheck the "Copy the main branch only" option**).
2. To initialize the repository with your layout:
   - Go to the **Actions** tab.
   - Select **Fetch and build layout**.
   - Click **Run workflow**.
   - Input your layout ID and keyboard type (your layout must be public in Oryx), then run the workflow.
   - (To avoid having to input values each time, you can modify the default values at the top of the `.github/workflows/fetch-and-build-layout.yml` file).
3. A folder containing your layout will be generated at the root of the repository.
4. You can now add your custom QMK features to this folder:
   - Edit `config.h`, `keymap.c` and `rules.mk` according to the [QMK documentation](https://github.com/qmk/qmk_firmware/tree/master/docs/features).
   - Commit and push to the **main** branch.
5. You can continue editing your layout through Oryx:
   - Make your changes in Oryx. 
   - Optionally, add a description of your changes in the **Some notes about what you changed** field; if provided, this will be used as commit message.
   - Confirm changes by clicking the **Compile this layout** button.
6. To build the firmware (including both Oryx and code modifications), rerun the GitHub Action. The firmware will be available for download in the action’s artifacts.
7. Flash your downloaded firmware using [Keymapp](https://www.zsa.io/flash#flash-keymap).
8. Enjoy!

## Troubleshooting

If the build fails with redeclaration errors or invalid driver types, **try re-compiling your layout in Oryx first** (click "Compile this layout"), then re-run the GitHub Action. ZSA periodically updates the QMK firmware structure (e.g. moving built-in drivers to QMK modules), and Oryx adapts its generated code accordingly. An older Oryx export may be incompatible with the current firmware branch.

## Oryx Chrome extension

To make building even easier, [@nivekmai](https://github.com/nivekmai) created an [Oryx Chrome extension](https://chromewebstore.google.com/detail/oryx-extension/bocjciklgnhkejkdfilcikhjfbmbcjal) to be able to trigger the GitHub Actions from inside Oryx itself.
