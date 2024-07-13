# Identities

* Users
* Groups
* Roles

## Permissions

When granting permissions, you decide who is getting the permissions, the resources that they get permissions for, and the specific actions that you want to allow on those resources.

### Default

By default, IAM users, groups, and roles have no permissions.

By default, a user has no permissions at all; this is sometimes called an implicit deny.

## Delegation

As an administrator in the management account of an organisation, you can perform administrative tasks or delegate administrator permissions to other IAM users or roles in your management account.

To do this, you attach an IAM permissions policy to an IAM user, group, or role.

By delegating, we practice explicit allow to specify the actions that the user can perform, and the resources they can perform actions on.

> If the permissions are granted to a role, users in other accounts in the organization can assume that role

# Links

1. [Managing access permissions for your AWS organization](https://docs.aws.amazon.com/organizations/latest/userguide/orgs_permissions_overview.html)
