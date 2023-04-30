### Dokumentacja wstępna projektu Techniki Kompilacji

## Opis języka
Zadany został kompilator języka **statycznie** oraz **słabo** typowanego. 
Zadeklarowane zmienne będą domyślnie traktowana jako **stałe**, natomiast 
przekazywanie zmiennych do funkcji będzie odbywać się przez **kopię**. 

## Przykładowe konstrukcje językowe 


# Typowanie statyczne:

```
int main(void){
    number;                                     # Error, statyczne typowanie
    number = 0;                                 # Error, statyczne typowanie

    int number = 0; 
    number += 1;                                # Error, number domyslnie jest const

    int mut mutable_number = 0;
    mutable_number = 1;                         # OK

    list<int> collection;
    list<int mut> collection_of_mutables;
    list<int> mut mutable_collection;

    collection.append(number);                   # Error, kolekcja jest stała
    mutable_collection.append(mutable_number);   # OK, mutowalny obiekt moze byc niezmieniany

    for int mut i = 0 ; i < 10 ; i+=1 { #body#} # OK
}
```
# Typowanie słabe:

typ mut - dowolny typ

nieczytelne
dopisać legendę na bazie ebnf


+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| wyrażenie            |  operacja   | wyrażenie 2 | poprawność | uwagi                                                                                   |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| typ var mut          | =,+,-,...   | typ  var    | TAK        | czy można dodać wartość mutowalną do niemutowalnej?                                     |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| typ                  | =,+,-,...   | typ mut     | TAK        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| fun(int mut var)     | przekazanie | int var     | TAK        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| fun(typ mut var)     | przekazanie | typ mut     | TAK        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| fun(typ mut &var)    | przekazanie | typ         | NIE        |                                                                                         | 
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| fun(typ mut &var)    | przekazanie | typ mut     | TAK        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+

Brakuje przypadku, kiedy funkcja deklaruje, że nie będzie mutować
Co jesli funkcja bierze 


+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| SZCZEGÓLNE PRZYPADKI |             |             |            |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| int                  | =,+,-,...   | str         | NIE        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| str                  | =,+,-,...   | int,float   | TAK        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| fun(str [mut] var)   | przekazanie | int, float  | TAK        |                                                                                         | // w przypadku 
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| bool                 | =           | typ         | TAK        | dowolny typ jeśli niepusty (str, list) lub większy niż 0 rzutowany jest na wartość true |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| typ                  | =,+,-,...   | bool        | NIE        |                                                                                         |
+----------------------+-------------+-------------+------------+-----------------------------------------------------------------------------------------+
| typ fun(...){..}     | return      | typ         | NIE        | rzutowanie wykonywane przy przypisaniu do wartości                                      |
+----------------------+-------------+-------------+------------+----------------------------------------------------------------

funkcja przez ref niemutowalną a typ jest mut
Najważniejsze (najbardziej niebezpieczne) są przypadki kiedy bierzemy przez referencję.



# Przekazywanie przez wartość i referencję
```
int foo_1(int var){#foo body#};             

int main(void){

    int number = 0;
    int mut mutable_number = 0;


    foo_1(int mut variable = 10);               # Error
    foo_1(int variable = 10);                   # OK


    int foo_2(int mut & var){#foo body#};       # OK przekazanie przez referencję, mozliwa modyfikacja zmiennej
    foo_2(int mut variable = 10);               # OK
    foo_2(int variable = 10);                   # Error

    int foo_3(int & var){ #foo body# };
    foo(int mut variable);                      # OK
}

Czy wtedy wykonuje się cast z mut na const?
```
# Typowanie słabe
```
# Rzutowanie typu moze nastapic tylko przez wartosc
int i_number = "1";                         # OK
i_number = 1.32;                            # OK, i_number == 1 
float f_number = "1.32";                    # OK, f_number == 1.32 
```

# Zdania warunkowe
```
    if letter in "abcd"{
        print("Forbidden letter")
    }
    else if letter in other_letters{
        
    }

```
# Przykład pętli warunkowych
    
    for int mut &element in container{ 
        element += "10"; 
    }

    for char letter in string = "word"{
        print(letter);
    }

    for int mut i = 0 ; i <= 10 ; i += 1{
        container[i] += "10";
    }

    int mut j = 10;

    while j < 10{
        if operation_on(j){
            print(j);
        }
        else{ break;}
    }


# Przykład definicji funkcji
int foo(int value){
    #body
    if value == 1 {
    return 1; 
    }
}

## Pattern matching 

Sprawdzenie, czy element jest typu int albo string

none identify(int & x){
  if x is int { print(x); };
  else if x is string && x is mut => {string += "word";}
}

Sprawdzenie, czy element przynalezy do zbioru

if letter in list<char> || letter in string word = "test" {
  # do something#
}



## Formalna specyfikacja gramatyki w EBNF

- program                           = {function_declaration | statement}

- statement                         = semicolon_terminated | non_semicolon_terminated;
- semicolon_terminated              = variable_instantiation | variable_declaration | function_call | expression | return_statement | "break", ";";
- non_semicolon_terminated         =  if_statement | for_loop | while_loop;

- variable_instantiation            = variable_declaration, '=', expression;
- variable_declaration              = type, ["mut"], identifier;
- value_assignment                  = identifier,'=', expression;



- expression                        = or_operand, {"||", or_operand};
- or_operand                        = and_operand, {"&&", and_operand};
- and_operand                       = comparison_operand, {comparison_operator, comparison_operand}
- comparison_operand                = term , {"+"| "/", term};
- term                              = factor, {"*" | "/", factor};
                                    = a, {"^", a};
- factor                            = ("(", expression, ")") | constant | identifier | object_access;                                                                       

- object_access                     = identifier , "." , identifier | function_call;

- function_call                     = identifier, "(" [function_argument], {",", function_argument} ")", ";";
- function_argument                 = identifier | identifier_reference |  variable_declaration | expression | literal;

- if_statement                      = "if", (expression | pattern_match) , code_block,  {"else if", code_block}, ["else", code_block];
- pattern_match                     = identifier , "is" | "in" variable_instantiation | value_assignment; 
- for_loop                          = "for", range_expression | smart_iteration, code_block;
- range_expression                  = variable_declaration, ",", expression, ",", expression;                                           
- smart_iteration                   = variable_declaration, "in", variable_declaration | identifier | expression| literal;
- while_loop                        = "while", expression, code_block;

- function_declaration              = variable_declaration, "(" type, ["&"], identifier, {",", type, [&], identifier} ")", code_block;
- return_statement                  = "return", [expression | literal | identifier | identifier_reference]  ";";


- comparison_operator               = "==" | "!=" | "<" | ">" | "<=" | ">=" ;
- identifier                        = ("_" | letter) , {"_" | letter | digit} ;  
- identifier_reference              = "&", identifier;

- letter                            = "a" | "b" | "c" | ... | "z" | "A" | "B" | "C" | ... | "Z";
- literal                            = integer | float | string | bool | list; 
- type                              = "integer"  | "float" | "string" | "bool" | "list" | "none" // typ none
- list                              = "[" list_element, {",", list_element} "]";
- list_element                      = identifier | expression | literal;
- bool                              = "True" | "False";
- string                            = """ , {letter} | " " | {special_character} | {new_line} | escaped_character, """;
- escaped_character                 = "\", special_character | "n" | "r";
- special_character                 = "!" | """ | "#" | "$" | ... | "/" | ":" | ";" | ... | "@" | "[" | ... | "'" | "{" | "~";
- float                             = integer , "." , digit | {digit};
- integer                           = non_zero_digit | {digit};
- digit                             = "0" | non_zero_digit;
- non_zero_digit                    = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";





## Obsługa błędów
# Błędy leksykalne
```
Lexical error:
l 15: int 7seven = 7;
          ^
Variable cannot start with number.

Lexical error
l 20: float number = .09829;
                     ^
Invalid value assignment

```

# Błędy składniowe

```
Syntax Error:
l 20: while(.){
            ^
Wrong boolean expression

_______________________________________

Syntax Error:
l 49: run_function(50, "Dollar";
                              ^
Missing ")".

Ten sam błąd ale występujący wcześniej.
Syntax Error:
l 49: run_functi(50, "Dollar");
      ^                              
Unknown identifier.

```

# Błędy semantyczne
```
Semantic Error:
l 14: get_salary("Adam", "January"); <- 
l 25: result = divide_numbers(10, 0); <-
l 27: return x/y 
             ^
Division by zero. 
_______________________________________

Semantic Error
l 10: a;
      ^
Identifier with no operation

_______________________________________

Semantic Error
l 10: a + b = c;
      ^
Lvalue expected on left side of "=" 


```
