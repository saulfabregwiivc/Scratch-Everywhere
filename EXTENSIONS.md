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
- Extension config: The `extension.json` file of the extension.

## Extension Library

## `extension.json`

This is equivalent to `getInfo` in normal Scratch extensions.

### Root Structure

- `blocks`: `Block[]` - An array of [block](#block-structure)s.
- `menus`: `{[id: string]: Menu}` - A list of menus usable as
  [argument](#argument-structure)s.

### Block Structure

- `opcode`: `string`: The opcode of the block.
- `type`: `"command" | "reporter" | "boolean" | "hat" | "event"`: The type/shape
  the block is.
- `arguments` (optional): `{[id: string]: Argument}`: The arguments of the
  block.

### Argument Structure

- `type`: `"string" | "number" | "boolean" | "color" | "angle" | "dummy"` - The
  type of the argument. The only key difference from normal Scratch extensions
  is that `dummy` should be used instead of `image`.
- `menu` (optional): `string` - The ID of a [menu](#menu-structure).

### Menu Structure

Menus of the type of `string[] | {string | number | boolean}[]`. This is roughly
the same as the `items` option on normal Scratch extension menus.
