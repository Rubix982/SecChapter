# Setting up Kubernets Goat using AWS CDK!

- Create a virtualenv (Assume you already have installed Python3 and it's available in the path)

```bash
python3 -m venv .venv
```

- Activate your virtualenv in MacOS & Linux

```bash
source .venv/bin/activate
```

- If you are a Windows platform, you would activate the virtualenv by running following command

```
% .venv\Scripts\activate.bat
```

- Once the virtualenv is activated, you can install the required dependencies

```bash
pip install -r requirements.txt
```

- If your AWS is not bootstrap with CDK, run the following

```bash
cdk bootstrap
```

- At this point you can now synthesize the CloudFormation template for this code

```bash
cdk synth
```

- Edit `.env` file according to your AWS environment

```bash
account_number=<1234567890> # Provide your AWS account number
default_region=<us-region-n> # Provide the AWS Region
vpc-id=<vpc-01234abcd> # VPC ID
instance_type=<t2.large or t2.medium> # Instance type t2.micro not recommended
key_pair_name=<kube-goat> # SSH Keypair name without .pem
whitelist_ip=<XX.XX.XX.XX/32> # 0.0.0.0/0 for public access, Recommended to whitelist for your network
```

- Now deploy this stack to your default AWS account/region

```bash
cdk deploy
```

- SSH to the deployed server using the SSH keypair

```bash
ssh -i key_pair_name.pem ubuntu@target_server
```

- Then to access the Kubernetes Goat locally by running the following command

```bash
sudo cd /kubernetes-goat
sudo bash access-kubernetes-goat.sh
```

- To destroy the setup, run the following command in your host system (where CDK was setup initally)

```bash
cdk destroy
```
