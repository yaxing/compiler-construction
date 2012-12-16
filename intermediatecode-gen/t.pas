program moresophisticated;

  type
     r1 = array [1..10] of integer;
    r2 = array[1..10] of r1;
        r3 = record
          ar : r2;
          ar1 : r1;
          int : integer;
        end;
   r5 = record
	ar : array[1..10] of r3;
   end;
  var
      	a:r1;
      	ab : r2;
     	arec : r3;
	arec1 : r5;
      	i,j,s: integer;
      	b: boolean;

  function f(i:integer):integer;

    var a,b: integer;

    begin
      if (((i=0) and (b < a)) or ((b - i) >= a)) then f:=1 else f := 2
    end;

  begin
    b:=true;
    b := not false;
    i := -10;
    j := 10; 
    for i:= 1 to j + 1 do
      begin
        a[i]:=f(i);
        ab[i][j+i] := 1;
        arec.ar1[i] := a[i];
	arec1.ar[i + j].ar[i][j] := a[i];
        s:=1;
        for j:=1 to i do s:=s*j;
        if (a[i]>s) then b:=false
      end;
    end.
