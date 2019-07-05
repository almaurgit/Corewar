.name "Nom"
.comment "Commentaire"

sti	r1, %:live, %1
sti	r1, %:xdxd, %1
and	r2, %0, r2
fork %:xdxd
live: live %1
zjmp %:live
xdxd: live %1
fork %:xdxd
ld %10, r8 #\n
#efouille
ld %101, r2 #e
ld %102, r3 #f
ld %111, r4 #o
ld %117, r5 #u
ld %105, r6 #i
ld %108, r7 #l
aff r2
aff r3
aff r4
aff r5
aff r6
aff r7
aff r7
aff r2
aff r8
#amaurel
ld %97, r3 #a
ld %109, r6 #m
ld %114, r9 #r
aff r3
aff r6
aff r3
aff r5
aff r9
aff r2
aff r7
aff r8
#rlegan
ld %103, r10 #g
ld %110, r11 #n
aff r9
aff r7
aff r2
aff r10
aff r3
aff r11
aff r8
#lduqueno
ld %100, r12 #d
ld %113, r13 #q
aff r7
aff r12
aff r5
aff r13
aff r5
aff r2
aff r11
aff r4
aff r8
aff r8
