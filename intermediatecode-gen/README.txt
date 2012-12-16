//
//Compiler Construction
// Project 4-Intermediate Code Generation
//
// @author Yaxing Chen(N16929794)

1. How to compile and run
(all files has to be in the same directory)

Verified running on CIMS machine: crunchy3.cims.nyu.edu

You can directly run: 
sh ./compile_run.sh <testfile>

Or run following commands:

flex lex.l
bison -d translate.y
gcc lex.yy.c translate.tab.c -ll -o SA.out
./SA.out < <testfile>


2. Output
Generated intermediate code is saved in : a.txt;

Semantic errors are output to stderr;

If turn on MODE_DEBUG in header.h:
Debugging information are saved in parser_debug.out;
Symbol table information are output to symtable.out;
(in symtable.out you could see the whole scope structure. 
except for the predefined table which is not being printed.
For refence: -1 is global scope, -2 is predefined type scope).
(Output might not be formatted under different OS).


3. Supported Types for type checking
Simple types:
	integer
	boolean
	char
	string

Type constructors:
	array
	record

Special types:
	function
	procedure
	undefined


4. Recursive definition
The analyser supports recursive definitions.
E.g.
type
	r = record
		s : string;
	    end;
	rRec = record
		rr : r;
	       end;
	arr = array[1..10] of rRec;
end;
var 
	t : arr;
	str : string;
begin
	str = t[0].rr.s;
end.


5. Caught semantic errors
1) Any used variable must have been declared first in its intended scope.

2) Catch multiple declarations of the same variable within the same scope.

3) Catch unequivalent types. 

Any incompatible types for such operation: a op b, would be detected. Also, any invalid variable component selection error would be detected. 
Moreover, if an array's index is not an integer or IF condition is not a boolean would be regarded as illegal as well.

E.g. using above code segment as an example. 

Statement: str = str.s would raise following errors:
	Invalid var: str is not a record
	Undeclared var: s
	Operation Betwween Incompatiable Types: Var(string), Default(undefined)

4) Catch unmatch parameters(quantity or type) for function/procedure calls.
For unmatch parameter qty, raise error:
 Incorrect parameter quantity for func/proc call: xxx

For incompatible parameter type, raise error:
 Incompatible parameter types: n1, n2,...
Where n* indicates which parameter's type is incompatible.


6. Brief implementation introduction
1) Scope
Following scopes are defined:
	global
	predefined(types)
	normal scopes(one for each function/procedure/record)
Each scope is stored in a hashmap, hashed by unique id.
Each scope owns a symbol table.
Scopes are formed as a tree. Each scope has a pointer points to it's enclosing scope node.
While parsing, there exists a scope stack to help building the tree structure.
Each record type has it's own scope.
 
2) Symbol table
Symbol table holds all registered symbols.
Type details of each symbol table entry is stored in a type descriptor.

3) Type descriptor
Type descriptors are formed as a linked list, containing unique type descriptors.
Each symbol table entry has a pointer pointing to it's type descriptor.
In this way it won's cost extra storage space for identical types.

Also, each descriptor is holding an union for specific type, e.g. array, record.
Therefore, unnecessary extra storage space is reduced the minimum amount.