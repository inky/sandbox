.include "header.asm"
.include "init.asm"

VBlank:  ; satisfy interrupt definition in header.asm
    RTI

.bank 0
.section "MainCode"

Start:
    Snes_Init

    ; Set background to green
    sep     #$20        ; set accumulator (A register) to 8-bit
    lda     #%10000000  ; force VBlank by turning off the screen
    sta     $2100
    lda     #%11100000  ; load low byte of the green color
    sta     $2122
    lda     #%00000000  ; load high byte of the green color
    sta     $2122
    lda     #%00001111  ; end VBlank, setting brightness to maximum (4-bit)
    sta     $2100

Forever:
    jmp Forever

.ends
