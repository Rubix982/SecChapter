# EBS vs EFS vs S3

| Feature/Aspect   | EBS                                      | EFS                                     | S3                                       |
| ---------------- |------------------------------------------|-----------------------------------------|------------------------------------------|
| *Storage Type*   | Block Storage                            | File Storage                            | Object Storage                           |
| *Performance*    | High performance, low latency            | Shared access, higher latency than EBS  | Scalable performance, variable latency   |
| *Use Cases*      | Databases, file systems, enterprise apps | Big data, content management, home dirs | Backup, archive, big data, content dist. |
| *Durability*     | 99.999%                                  | 99.999999999%                           | 99.999999999%                            |
| *Scalability*    | Scales up to 16 TiB per volume           | Automatically scales to petabytes       | Automatically scales to petabytes        |
| *Accessibility*  | Single EC2 instance in same AZ           | Multiple EC2 instances across AZs       | Global access                            |
| *Management*     | Requires management for snapshots        | Fully managed                           | Fully managed                            |
| *Cost*           | Pay for provisioned capacity             | Pay per use, elastic pricing            | Pay per use, various storage classes     |

## Object Storage vs Block Storage

| Aspect              | Object Storage                        | Block Storage                                   |
| ------------------- | ------------------------------------- |-------------------------------------------------|
| *Data Management* | Managed as objects with metadata      | Managed as fixed-size blocks                    |
| *Access Method*   | Accessed via APIs                     | Accessed via the operating system               |
| *Scalability*     | Highly scalable                       | More complex to scale                           |
| *Performance*     | Generally lower performance           | High performance, low latency                   |
| *Metadata*        | Extensive metadata support            | Limited to block addresses                      |
| *Cost*            | Cost-effective for large data volumes | Can be more expensive                           |
| *Use Case*        | Unstructured data, backups, archives  | Databases, VM file systems, enterprise apps     |
| *Durability*      | High durability with redundancy       | Typically requires manual redundancy management |
