# MCP45HVX1 Hardware Validation Checklist

This file records hardware checks that must be completed before removing the
address-conflict caveat from the driver documentation.

## I2C Address Conflict

The internal docs record a DS20005304B conflict:

- Table/text path: fixed bits `01111`, 7-bit address range `0x3C-0x3F`
- Command-figure path: fixed bits `10111`, 7-bit address range `0x5C-0x5F`

The driver defaults to `0x3C-0x3F`. The `0x5C-0x5F` range is accepted only when
`Config::allowAlternateAddressRange` is enabled.

## Required Bench Record

For each A1:A0 pin combination, record the responding 7-bit address using the
`scan` CLI command:

| A1 | A0 | Expected if table is correct | Expected if figures are correct | Observed |
|---:|---:|---:|---:|---|
| 0 | 0 | `0x3C` | `0x5C` | Pending bench test |
| 0 | 1 | `0x3D` | `0x5D` | Pending bench test |
| 1 | 0 | `0x3E` | `0x5E` | Pending bench test |
| 1 | 1 | `0x3F` | `0x5F` | Pending bench test |

## General Call Check

Because `GCEN` is referenced but not located in the extracted register map,
record whether each General Call helper ACKs and whether `read` confirms the
expected local state afterward:

| Command | ACK/NACK | Local state verified after read |
|---|---|---|
| `gc arm`, `gc wiper <code>` | Pending bench test | Pending bench test |
| `gc arm`, `gc tcon <value>` | Pending bench test | Pending bench test |
| `gc arm`, `gc inc` | Pending bench test | Pending bench test |
| `gc arm`, `gc dec` | Pending bench test | Pending bench test |
