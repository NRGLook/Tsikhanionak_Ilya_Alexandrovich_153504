 ldx #%0011001100110011
 ldy #%1100110011001111
 stx $9003 
 sty $9005
 ldaa $9004 //????????? ? ??????? a ??????? ???? x 
 anda $9006 //?????? ?????????? ? ? ??????? ?????? y
 staa $9009 //????????? ??????? ???? ??????????? ????????
 ldaa $9003 //????????? ? ??????? a ??????? ???? x
 anda $9005 //?????????? ? ?? ??????? ?????? y
 staa $9008 //????????? ??????? ???? ??????????? ????????