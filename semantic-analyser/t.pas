{
	This program is lexical and parsing error-free.
    It contains unequivalent type errors
}

program errorfree;
type
s = string;
in = integer;
var
z : string;
m : in;
b : boolean;


function foo(a : in) : in;
begin
a := a + 1;
foo := a
end;


begin
m := 1 > 2;
end.