program foo;

  type r1 = array [1..10] of integer;
  r2 = record
    a : r1;
    b : integer;
  end;
  r3 = array[1..10] of r2;

  var a:r1;
      i,j,s: integer;
      b: boolean;
       x: r2;
	mk:r3;
      
  function f(i:integer):integer;

    var a,b: integer;

    begin
      if (i=0) then f:=1
    end;

  begin
    b:=true;
    for i:= 1 to 10 do
      begin
        a[i]:=f(i);
        s:=1;
        for j:=1 to i do s:=s*j;
        if (a[i]>s) then b:=false
      end;
	a[x.b] := j;
        a[mk[j].a[i]] := j;
    end.
