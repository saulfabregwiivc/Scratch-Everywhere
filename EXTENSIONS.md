# Extensions

This is the documentation about the custom extension format. A lot of things are
identical to normal Scratch extensions so for more detail, see
[TurboWarp's Extension Docs](https://docs.turbowarp.org/development/extensions/introduction).

> [!NOTE]
> All types are in TypeScript syntax.

## Glossary

- Extension folder: The extension folder is `sdcard:/3ds/extensions` on 3DS,
  `sdcard:/wiiu/scratch-wiiu/extension` on Wii U, and `./extensions` on PC.
- Extension library: The code or compiled library of a extension.

## Directory Structure

The directory structure is pretty simple, it's just a directory with the
extensions id within the extensions folder with a
`extension.so`/`extension.rpl`/`extension.dll`/`extension.dylib` file.

## Extension Library
