; http://en.wikibooks.org/wiki/Super_NES_Programming

;==LoRom==

.MEMORYMAP                      ; Begin describing the system architecture.
    SLOTSIZE $8000                ; The slot is $8000 bytes in size.
    DEFAULTSLOT 0
    SLOT 0 $8000                  ; Defines Slot 0's starting address.
.ENDME

.ROMBANKSIZE $8000              ; Every ROM bank is 32 KBytes in size
.ROMBANKS 8                     ; 2 Mbits - Tell WLA we want to use 8 ROM Banks

.SNESHEADER
    ID "SNES"                     ; 1-4 letter string, just leave it as "SNES"

    NAME "inky's SNES Sandbox  "  ; Program Title - can't be over 21 bytes,
    ;    "123456789012345678901"  ; use spaces for unused bytes of the name.

    SLOWROM
    LOROM

    CARTRIDGETYPE $00           ; $00 = ROM only, see WLA documentation for others
    ROMSIZE $08                 ; $08 = 2 Mbits,  see WLA doc for more..
    SRAMSIZE $00                ; No SRAM         see WLA doc for more..
    COUNTRY $01                 ; $01 = U.S.  $00 = Japan, that's all I know
    LICENSEECODE $00            ; Just use $00g,
    VERSION $00                 ; $00 = 1.00, $01 = 1.01, etc.
.ENDSNES

.SNESNATIVEVECTOR               ; Define Native Mode interrupt vector table
    COP EmptyHandler
    BRK EmptyHandler
    ABORT EmptyHandler
    NMI VBlank
    IRQ EmptyHandler
.ENDNATIVEVECTOR

.SNESEMUVECTOR                  ; Define Emulation Mode interrupt vector table
    COP EmptyHandler
    ABORT EmptyHandler
    NMI EmptyHandler
    RESET Start                 ; where execution starts
    IRQBRK EmptyHandler
.ENDEMUVECTOR

.BANK 0 SLOT 0                  ; Defines the ROM bank and the slot it is inserted in memory.
.ORG 0                          ; .ORG 0 is really $8000, because the slot starts at $8000
.SECTION "EmptyVectors" SEMIFREE

EmptyHandler:
    rti

.ENDS

.EMPTYFILL $00                  ; fill unused areas with $00, opcode for BRK.
                                ; BRK will crash the snes if executed.
