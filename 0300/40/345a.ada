with Ada.Strings;
with Ada.Text_IO;
with Ada.Float_Text_IO;

procedure Main is
    S : String(1..50);
    N : Natural;
    P : Float;
    V : Float;
begin
    Ada.Text_IO.Get_Line(S, N);
    Ada.Float_Text_IO.Get(Item => P);

    V := 0.0;
    For I in 1..N loop
        if S(I) = '1' then
            V := V + 1.0;
        elsif S(I) = '?' then
            V := V + P;
        end if;
    end loop;

    Ada.Float_Text_IO.Put(Item => V / Float(N), Exp => 0);
end;
