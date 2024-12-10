.class public Lcom/example/mobpsycho/Tips;
.super Landroidx/appcompat/app/AppCompatActivity;
.source "Tips.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .line 8
    invoke-direct {p0}, Landroidx/appcompat/app/AppCompatActivity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 5
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .line 12
    invoke-super {p0, p1}, Landroidx/appcompat/app/AppCompatActivity;->onCreate(Landroid/os/Bundle;)V

    .line 13
    sget v0, Lcom/example/mobpsycho/R$layout;->activity_tips:I

    invoke-virtual {p0, v0}, Lcom/example/mobpsycho/Tips;->setContentView(I)V

    .line 14
    sget v0, Lcom/example/mobpsycho/R$id;->tip1:I

    invoke-virtual {p0, v0}, Lcom/example/mobpsycho/Tips;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/TextView;

    .line 15
    .local v0, "tip1TextView":Landroid/widget/TextView;
    sget v1, Lcom/example/mobpsycho/R$id;->tip2:I

    invoke-virtual {p0, v1}, Lcom/example/mobpsycho/Tips;->findViewById(I)Landroid/view/View;

    move-result-object v1

    check-cast v1, Landroid/widget/TextView;

    .line 16
    .local v1, "tip2TextView":Landroid/widget/TextView;
    sget v2, Lcom/example/mobpsycho/R$id;->tip3:I

    invoke-virtual {p0, v2}, Lcom/example/mobpsycho/Tips;->findViewById(I)Landroid/view/View;

    move-result-object v2

    check-cast v2, Landroid/widget/TextView;

    .line 17
    .local v2, "tip3TextView":Landroid/widget/TextView;
    sget v3, Lcom/example/mobpsycho/R$id;->tip4:I

    invoke-virtual {p0, v3}, Lcom/example/mobpsycho/Tips;->findViewById(I)Landroid/view/View;

    move-result-object v3

    check-cast v3, Landroid/widget/TextView;

    .line 20
    .local v3, "tip4TextView":Landroid/widget/TextView;
    const-string v4, "Tip 1: Use Strong Passwords - Create complex passwords and avoid using the same password for multiple accounts."

    invoke-virtual {v0, v4}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 21
    const-string v4, "Tip 2: Keep Software Updated - Regularly update your apps and operating system to patch security vulnerabilities."

    invoke-virtual {v1, v4}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 22
    const-string v4, "Tip 3: Be Cautious with Downloads - Only download apps and files from trusted sources."

    invoke-virtual {v2, v4}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 23
    const-string v4, "Tip 4: Use Secure Wi-Fi Connections - Avoid using public Wi-Fi for sensitive activities like banking or shopping."

    invoke-virtual {v3, v4}, Landroid/widget/TextView;->setText(Ljava/lang/CharSequence;)V

    .line 24
    return-void
.end method
