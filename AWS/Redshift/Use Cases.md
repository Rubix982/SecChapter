# Use Cases

## Load JSON files from S3 and  perform analysis

* Store an S3 Bucket and Upload JSON Files
* Create an Amazon Redshift Cluster
* Create a Redshift Table,
    * Define a table in Redshift that will hold the data. For JSON data, you might use a SUPER column type (if using Redshift's semi-structured data feature) or define a specific schema.
* Create an IAM Role with S3 Access,
    * - Create an IAM role with the necessary permissions to access your S3 bucket.
    * Attach this role to your Redshift cluster.
* Use COPY Command to Load Data,
    * Define a table in Redshift that will hold the table. For JSON data, you might use the JSON 'auto' parameter for such cases, or a JSONPaths file for more complex JSON structures.

### Create a table in Redshift

```sql
CREATE TABLE my_table (
id INT,
name VARCHAR(255),
attributes SUPER
);
```

### Create an IAM Role

Ensure the IAM role has the necessary permissions,

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Effect": "Allow",
      "Action": "s3:GetObject",
      "Resource": "arn:aws:s3:::my-bucket/*"
    }
  ]
}
```

### Attach the IAM Role to the Redshift Cluster

* Go to the Redshift console
* Select your cluster
* Attach the IAM role

### Use the COPY Command

```sql
COPY my_table
FROM 's3://my-bucket/my-json-file.json'
IAM_ROLE 'arn:aws:iam::account-id:role/my-redshift-role'
JSON 'auto';
```

### Queries

With the data loaded into Redshift, you can run queries on it,

* For columns with simple types (e.g., id, name), you can run standard SQL queries,

```sql
SELECT id, name FROM my_table WHERE id = 1;
```

- For the SUPER column (attributes), you can use the JSON functions provided by Redshift,

```sql
SELECT attributes['key1'] AS key1_value FROM my_table WHERE id = 1;
```

### Tips

#### Complex JSON Structures

If your JSON structure is complex, consider using a JSONPaths file to map JSON data to Redshift columns.

#### Performance

For better performance, consider loading data into staging tables and then transforming and inserting it into the final tables.

#### Redshift Spectrum

For querying large amounts of semi-structured data directly in S3 without loading it into Redshift, consider using Redshift Spectrum.