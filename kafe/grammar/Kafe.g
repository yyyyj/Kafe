grammar Kafe;

chunk
    : block EOF
    ;

block
    : stat*
    ;

stat
    : 'dyn' NAME ':' type '=' explist
    | NAME '=' explist
    | functioncall
    | 'for' NAME 'in' exp 'do' block 'end'
    | 'if' exp 'then' block ('elif' exp 'then' block)* ('else' block)? 'end'
    | 'while' exp 'do' block 'end'
    | 'func' NAME ':' type argslist? funcbody
    | 'struct' NAME argslist? structbody
    ;

retstat
    : 'ret' exp
    ;

type
    : 'string'
    | 'int'
    | 'double'
    | 'list'
    | 'bool'
    | 'struct' NAME
    ;

explist
    : exp exp*
    ;

functioncall
    : '(' NAME explist* ')'
    ;

exp
    : 'nil' | 'false' | 'true'
    | number
    | string
    | list
    | functioncall
    | <assoc=right> exp operatorPower exp
    | operatorUnary exp
    | exp operatorMulDivMod exp
    | exp operatorAddSub exp
    | <assoc=right> exp operatorStrcat exp
    | exp operatorComparison exp
    | exp operatorAnd exp
    | exp operatorOr exp
    | exp operatorBitwise exp
    ;

argslist
    : '--' (NAME ':' type ','?)+
    ;

funcbody
    : block retstat
    ;

structbody
    : block 'end'
    ;

operatorOr 
	: 'or';

operatorAnd 
	: 'and';

operatorComparison 
	: '<' | '>' | '<=' | '>=' | '!=' | '==';

operatorStrcat
	: '..';

operatorAddSub
	: '+' | '-';

operatorMulDivMod
	: '*' | '/' | '%' | '//';

operatorBitwise
	: '&' | '|' | '~' | '<<' | '>>' | '^';

operatorUnary
    : 'not' | '-' | '~';

operatorPower
    : '**';

number
    : INT | HEX | FLOAT | HEX_FLOAT
    ;

string
    : NORMALSTRING | CHARSTRING
    ;

list
    : '[' explist ']'
    ;

// LEXER

NAME
    : [a-zA-Z_][a-zA-Z_0-9]*
    ;

NORMALSTRING
    : '"' ( EscapeSequence | ~('\\'|'"') )* '"' 
    ;

CHARSTRING
    : '\'' ( EscapeSequence | ~('\''|'\\') )* '\''
    ;

INT
    : Digit+
    ;

HEX
    : '0' [xX] HexDigit+
    ;

FLOAT
    : Digit+ '.' Digit* ExponentPart?
    | '.' Digit+ ExponentPart?
    | Digit+ ExponentPart
    ;

HEX_FLOAT
    : '0' [xX] HexDigit+ '.' HexDigit* HexExponentPart?
    | '0' [xX] '.' HexDigit+ HexExponentPart?
    | '0' [xX] HexDigit+ HexExponentPart
    ;

fragment
ExponentPart
    : [eE] [+-]? Digit+
    ;

fragment
HexExponentPart
    : [pP] [+-]? Digit+
    ;

fragment
EscapeSequence
    : '\\' [abfnrtvz"'\\]
    | '\\' '\r'? '\n'
    | HexEscape
    | UtfEscape
    ;

fragment
HexEscape
    : '\\' 'x' HexDigit HexDigit
    ;

fragment
UtfEscape
    : '\\' 'u{' HexDigit+ '}'
    ;

fragment
Digit
    : [0-9]
    ;

fragment
HexDigit
    : [0-9a-fA-F]
    ;

COMMENT
    : '#' .*? -> channel(HIDDEN)
    ;

WS  
    : [ \t\u000C\r\n]+ -> skip
    ;
