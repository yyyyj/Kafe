// -----------------------------------------------------------------
// Kafe - A programming language running on a VM
// 
// Copyright (c) 2018 SuperFola and the Kafe open source project
// Licensed under MPL-2.0
// 
// This notice may not be removed or altered from any source ditribution
// 
// See https://superfola.github.io/Kafe/CONTRIBUTORS.txt for the list of Kafe project authors
// See https://superfola.github.io/Kafe/LICENSE for license information
// -----------------------------------------------------------------

grammar Kafe;

chunk
    : block EOF
    ;

block
    : stat*
    ;

stat
    : varqualifier NAME '=' explist
    | varqualifier NAME ':' NAME '(' explist* ')'
    | 'nonlocal' namelist
    | NAME '=' explist
    | NAME operatorMathAffectation explist
    | functioncall
    | 'for' NAME 'in' exp 'do' block 'end'
    | 'if' exp 'then' block ('elif' exp 'then' block)* ('else' block)? 'end'
    | 'while' exp 'do' block 'end'
    | 'fun' NAME argslist '->' type funcbody
    | 'Obj' NAME structparents? structbody
    | getstructmember
    ;

retstat
    : 'ret' exp
    ;

varqualifier
    : 'dyn' | 'cst'
    ;

type
    : 'string'
    | 'int'
    | 'double'
    | 'list'
    | 'bool'
    | 'Obj' NAME
    ;

namelist
    : NAME (','? NAME)*
    ;

explist
    : exp (','? exp)*
    ;

getstructmember
    : NAME '.' (NAME | getstructmember)
    ;

functioncall
    : (NAME | getstructmember) '(' explist* ')'
    ;

exp
    : 'nil' | 'false' | 'true'
    | number
    | string
    | list
    | NAME
    | functioncall
    | getstructmember
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
    : '(' (NAME ':' type ','?)* ')'
    ;

funcbody
    : block retstat
    ;

structparentslist
    : NAME (','? structparentslist)*
    ;

structparents
    : ':' structparentslist
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

operatorMathAffectation
    : '+=' | '-=' | '*=' | '/=' | '%=' | '**=' | '..=' | '&=' | '|=' | '<<=' | '>>=' | '^=';

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
    : '#' ~[\r\n]* -> skip
    ;

WS  
    : [ \t\u000C\r\n]+ -> skip
    ;
