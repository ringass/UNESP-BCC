;DATA: 02/11/2025
;PROGRAMA "TIMER E SERIAL"

INCLUDE <P16F873A.INC>
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _BOREN_ON & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF

TICK    EQU 0X20 ;tick para piscar led
READ    EQU 0X21 ;variavel para recebimento do RX
NEW_TICK    EQU 0X22 ;novo valor de tick, convertido de READ
BAUDRATE    EQU d'25' ;baudrate 9600
SPEED1  EQU d'15' ;0.125s
SPEED2  EQU d'31' ;0.250s
SPEED3  EQU d'62' ; 0.5s
SPEED4  EQU d'125'; 1s

        ORG 0X0
        GOTO INIT
    
        ORG 0X4     ;interrupção
            BCF INTCON, T0IF ; limpando flag de interrupção

            MOVLW D'131'
            MOVWF TMR0 ;recarga do timer0

            DECFSZ TICK, 1 ;decrementa e verifica se é zero
            RETFIE ;retorno da interrupção
            ;se zero, lógica para piscar led e 
            BANKSEL PORTB
            MOVLW B'10000000'
            XORWF PORTB, 1 ;altera o estado do RB7
            MOVF NEW_TICK, W
            MOVWF TICK  ;redefine a variável TICK
            RETFIE ;retorno da interrupção

;configuracao dos registradores de entrada e saida 
CONFIG_IO: 
    BANKSEL TRISB
    CLRF TRISB  ;portas setadas como saida

    BANKSEL TRISC
    MOVLW B'10000000'
    MOVWF TRISC   ; rx = rc7 e tx = rc6

    BANKSEL PORTB
    CLRF PORTB    ;iniciando todas as portas em 0
    RETURN

;configuracao da interrupcao
CONFIG_INT:
    BANKSEL OPTION_REG
    MOVLW B'10000101'   
    MOVWF OPTION_REG 

    BANKSEL TMR0
    MOVLW D'131' ;125 interrupcoes por segundo
    MOVWF TMR0 

    BANKSEL INTCON
    MOVLW B'10100000'
    MOVWF INTCON 
    RETURN

;configuracao da UART
CONFIG_UART
    BANKSEL SPBRG
    MOVLW BAUDRATE
    MOVWF SPBRG ;setando baudrate

    BANKSEL TXSTA
    MOVLW B'00100100'
	MOVWF TXSTA

    BANKSEL RCSTA
	MOVLW b'10010000'
	MOVWF RCSTA
    RETURN

INIT:

    CALL CONFIG_IO

    CALL CONFIG_UART

    CALL CONFIG_INT

    MOVLW SPEED1
    MOVWF TICK
    MOVWF NEW_TICK ;atribuicao de valor para que na primeira iterracao nao contenha lixo

WAIT_RX:
    BANKSEL PIR1
    BTFSS PIR1, RCIF ; verifica se rcif é alto, ou seja, recebeu algum byte
    GOTO WAIT_RX

    BANKSEL RCREG
    MOVF RCREG, w
    MOVWF READ

    ;ifs
    MOVLW D'1'
    SUBWF READ,0;
    BTFSC STATUS,Z;
    GOTO IF_1; 
    
    MOVLW D'2'
    SUBWF READ,0;
    BTFSC STATUS,Z; 
    GOTO IF_2;

    MOVLW D'3'
    SUBWF READ,0;
    BTFSC STATUS,Z; 
    GOTO IF_3

    MOVLW D'4'
    SUBWF READ,0;
    BTFSC STATUS,Z;
    GOTO IF_4;

    GOTO WAIT_RX;

IF_1:
    MOVLW SPEED1
	MOVWF NEW_TICK
	GOTO WAIT_TX
IF_2:
    MOVLW SPEED2
	MOVWF NEW_TICK
	GOTO WAIT_TX
IF_3:   
    MOVLW SPEED3
	MOVWF NEW_TICK
	GOTO WAIT_TX
IF_4:
    MOVLW SPEED4
	MOVWF NEW_TICK
	GOTO WAIT_TX

WAIT_TX:
    BANKSEL PIR1
    BTFSS PIR1, TXIF ;verifica se o buffer do TX esta alto, ou seja, disponivel para transmissao
    GOTO WAIT_TX

    MOVF NEW_TICK, w
    MOVWF TXREG
    GOTO WAIT_RX

    END







    



    

    





