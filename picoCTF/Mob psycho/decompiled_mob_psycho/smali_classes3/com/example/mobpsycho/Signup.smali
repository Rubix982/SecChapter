.class public Lcom/example/mobpsycho/Signup;
.super Landroidx/appcompat/app/AppCompatActivity;
.source "Signup.java"


# direct methods
.method public constructor <init>()V
    .locals 0

    .line 10
    invoke-direct {p0}, Landroidx/appcompat/app/AppCompatActivity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 2
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .line 15
    invoke-super {p0, p1}, Landroidx/appcompat/app/AppCompatActivity;->onCreate(Landroid/os/Bundle;)V

    .line 16
    sget v0, Lcom/example/mobpsycho/R$layout;->activity_signup:I

    invoke-virtual {p0, v0}, Lcom/example/mobpsycho/Signup;->setContentView(I)V

    .line 17
    sget v0, Lcom/example/mobpsycho/R$id;->buttonSignUp:I

    invoke-virtual {p0, v0}, Lcom/example/mobpsycho/Signup;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/Button;

    .line 18
    .local v0, "nextButton":Landroid/widget/Button;
    new-instance v1, Lcom/example/mobpsycho/Signup$1;

    invoke-direct {v1, p0}, Lcom/example/mobpsycho/Signup$1;-><init>(Lcom/example/mobpsycho/Signup;)V

    invoke-virtual {v0, v1}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    .line 25
    return-void
.end method
