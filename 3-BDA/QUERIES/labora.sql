/*. List the cyclist number and the name of the cyclists 
who have not worn all the jerseys worn by the cyclist
with number 20.
=
list the cyclist number and the name of the cyclists such that
doesn't exists a jersey worn by number 20 they have worn
*/

select distinct c.cnum,c.name
from cyclist c,wear w
where not exists(select * from jersey j where 
w.cnum=20 and  j.code=w.code 
and j.code in (select w2.code from wear w2 where w2.cnum=c.cnum))
order by c.cnum;


