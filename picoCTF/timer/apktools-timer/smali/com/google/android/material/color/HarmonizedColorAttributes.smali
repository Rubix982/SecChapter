.class public final Lcom/google/android/material/color/HarmonizedColorAttributes;
.super Ljava/lang/Object;
.source "HarmonizedColorAttributes.java"


# static fields
.field private static final HARMONIZED_MATERIAL_ATTRIBUTES:[I


# instance fields
.field private final attributes:[I

.field private final themeOverlay:I


# direct methods
.method static constructor <clinit>()V
    .locals 3

    .line 34
    const/4 v0, 0x4

    new-array v0, v0, [I

    sget v1, Lcom/google/android/material/R$attr;->colorError:I

    const/4 v2, 0x0

    aput v1, v0, v2

    sget v1, Lcom/google/android/material/R$attr;->colorOnError:I

    const/4 v2, 0x1

    aput v1, v0, v2

    sget v1, Lcom/google/android/material/R$attr;->colorErrorContainer:I

    const/4 v2, 0x2

    aput v1, v0, v2

    sget v1, Lcom/google/android/material/R$attr;->colorOnErrorContainer:I

    const/4 v2, 0x3

    aput v1, v0, v2

    sput-object v0, Lcom/google/android/material/color/HarmonizedColorAttributes;->HARMONIZED_MATERIAL_ATTRIBUTES:[I

    return-void
.end method

.method private constructor <init>([II)V
    .locals 2
    .param p1, "attributes"    # [I
    .param p2, "themeOverlay"    # I

    .line 89
    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    .line 90
    if-eqz p2, :cond_1

    array-length v0, p1

    if-eqz v0, :cond_0

    goto :goto_0

    .line 91
    :cond_0
    new-instance v0, Ljava/lang/IllegalArgumentException;

    const-string v1, "Theme overlay should be used with the accompanying int[] attributes."

    invoke-direct {v0, v1}, Ljava/lang/IllegalArgumentException;-><init>(Ljava/lang/String;)V

    throw v0

    .line 94
    :cond_1
    :goto_0
    iput-object p1, p0, Lcom/google/android/material/color/HarmonizedColorAttributes;->attributes:[I

    .line 95
    iput p2, p0, Lcom/google/android/material/color/HarmonizedColorAttributes;->themeOverlay:I

    .line 96
    return-void
.end method

.method public static create([I)Lcom/google/android/material/color/HarmonizedColorAttributes;
    .locals 2
    .param p0, "attributes"    # [I

    .line 50
    new-instance v0, Lcom/google/android/material/color/HarmonizedColorAttributes;

    const/4 v1, 0x0

    invoke-direct {v0, p0, v1}, Lcom/google/android/material/color/HarmonizedColorAttributes;-><init>([II)V

    return-object v0
.end method

.method public static create([II)Lcom/google/android/material/color/HarmonizedColorAttributes;
    .locals 1
    .param p0, "attributes"    # [I
    .param p1, "themeOverlay"    # I

    .line 64
    new-instance v0, Lcom/google/android/material/color/HarmonizedColorAttributes;

    invoke-direct {v0, p0, p1}, Lcom/google/android/material/color/HarmonizedColorAttributes;-><init>([II)V

    return-object v0
.end method

.method public static createMaterialDefaults()Lcom/google/android/material/color/HarmonizedColorAttributes;
    .locals 2

    .line 85
    sget-object v0, Lcom/google/android/material/color/HarmonizedColorAttributes;->HARMONIZED_MATERIAL_ATTRIBUTES:[I

    sget v1, Lcom/google/android/material/R$style;->ThemeOverlay_Material3_HarmonizedColors:I

    invoke-static {v0, v1}, Lcom/google/android/material/color/HarmonizedColorAttributes;->create([II)Lcom/google/android/material/color/HarmonizedColorAttributes;

    move-result-object v0

    return-object v0
.end method


# virtual methods
.method public getAttributes()[I
    .locals 1

    .line 101
    iget-object v0, p0, Lcom/google/android/material/color/HarmonizedColorAttributes;->attributes:[I

    return-object v0
.end method

.method public getThemeOverlay()I
    .locals 1

    .line 107
    iget v0, p0, Lcom/google/android/material/color/HarmonizedColorAttributes;->themeOverlay:I

    return v0
.end method
