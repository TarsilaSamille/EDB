-- DELETE 
--     FROM flyway_schema_history 
--     WHERE installed_rank=114
-- ; 

EXEC sp_rename 'malha_seguranca.clp_id', 'clp_seguranca_id', 'COLUMN';

EXEC sp_rename 'dbo.clp', 'clp_seguranca';

create sequence clp_seguranca_id_seq start with 400 increment by 1;

DROP SEQUENCE clp_id_seq;
