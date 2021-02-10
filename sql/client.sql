create table if not exists client(id integer primary key, ip text not null, port text not null);
insert into client(id,ip,port) values(1,'localhost','3331');
insert into client(id,ip,port) values(2,'localhost','3332');
insert into client(id,ip,port) values(3,'localhost','3333');
insert into client(id,ip,port) values(4,'localhost','3334');
