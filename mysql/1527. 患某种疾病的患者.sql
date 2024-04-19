SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions LIKE "% DIAB1%"
    OR conditions LIKE "DIAB1%";

-- Solution 2 正则表达式
SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions REGEXP '\\bDIAB1.*';