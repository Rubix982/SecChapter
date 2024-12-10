.class Lcom/example/mobpsycho/Signup$1;
.super Ljava/lang/Object;
.source "Signup.java"

# interfaces
.implements Landroid/view/View$OnClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/example/mobpsycho/Signup;->onCreate(Landroid/os/Bundle;)V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Lcom/example/mobpsycho/Signup;


# direct methods
.method constructor <init>(Lcom/example/mobpsycho/Signup;)V
    .locals 0
    .param p1, "this$0"    # Lcom/example/mobpsycho/Signup;

    .line 18
    iput-object p1, p0, Lcom/example/mobpsycho/Signup$1;->this$0:Lcom/example/mobpsycho/Signup;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 3
    .param p1, "view"    # Landroid/view/View;

    .line 21
    new-instance v0, Landroid/content/Intent;

    iget-object v1, p0, Lcom/example/mobpsycho/Signup$1;->this$0:Lcom/example/mobpsycho/Signup;

    const-class v2, Lcom/example/mobpsycho/Tips;

    invoke-direct {v0, v1, v2}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    .line 22
    .local v0, "intent":Landroid/content/Intent;
    iget-object v1, p0, Lcom/example/mobpsycho/Signup$1;->this$0:Lcom/example/mobpsycho/Signup;

    invoke-virtual {v1, v0}, Lcom/example/mobpsycho/Signup;->startActivity(Landroid/content/Intent;)V

    .line 23
    return-void
.end method
