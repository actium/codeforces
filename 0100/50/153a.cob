       PROGRAM-ID. 153A.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 A        PIC 9(10) VALUE ZEROES.
       01 B        PIC 9(10) VALUE ZEROES.
       01 S        PIC X(10).

       PROCEDURE DIVISION.
         ACCEPT S
         MOVE S TO A
         ACCEPT S
         MOVE S TO B
         ADD A TO B
         MOVE B TO S
         INSPECT S REPLACING LEADING '0' BY ' '
         DISPLAY S
         STOP RUN.
