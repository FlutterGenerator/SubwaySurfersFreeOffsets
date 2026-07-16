bool titleValid, headingValid, iconValid, settingsValid, isLeeched;

void *antiLeech(void *) {
    sleep(20);

    if (!titleValid || !headingValid || !iconValid || !settingsValid) {
        int *p = 0;
        *p = 0;
    }
    return NULL;
}
const char *copyText;
const char *copy() {
    return copyText;
}
bool copy(const char *t) {
    copyText = t;
    return true;
}

void setText(JNIEnv *env, jobject obj, const char* text){
    //https://stackoverflow}.com/a/33627640/3763113
    //A little JNI calls here. You really really need a great knowledge if you want to play with JNI stuff
    //Html.fromHtml("");
    jclass html = (*env).FindClass(OBFUSCATE("android/text/Html"));
    jmethodID fromHtml = (*env).GetStaticMethodID(html, OBFUSCATE("fromHtml"), OBFUSCATE("(Ljava/lang/String;)Landroid/text/Spanned;"));

    //setText("");
    jclass textView = (*env).FindClass(OBFUSCATE("android/widget/TextView"));
    jmethodID setText = (*env).GetMethodID(textView, OBFUSCATE("setText"), OBFUSCATE("(Ljava/lang/CharSequence;)V"));

    //Java string
    jstring jstr = (*env).NewStringUTF(text);
    (*env).CallVoidMethod(obj, setText,  (*env).CallStaticObjectMethod(html, fromHtml, jstr));
}

extern "C" {
JNIEXPORT void JNICALL
Java_com_dz_offset_FloatingModMenuService_setTitleText(JNIEnv *env, jobject thiz, jobject obj) {
    setText(env, obj, OBFUSCATE("<b>DZ OFFSETS</b>"));

    titleValid = true;
}

JNIEXPORT void JNICALL
Java_com_dz_offset_FloatingModMenuService_setHeadingText(JNIEnv *env, jobject thiz, jobject obj) {
    setText(env, obj, OBFUSCATE("Deadtarget - Dumper"));

    headingValid = true;
}

JNIEXPORT jstring JNICALL
Java_com_dz_offset_FloatingModMenuService_Icon(JNIEnv *env, jobject thiz) {
    iconValid = true;

    //Use https://www.base64encode.org/ to encode your image to base64
    return env->NewStringUTF(
            OBFUSCATE("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"));
             }
JNIEXPORT jstring JNICALL
Java_com_dz_offset_FloatingModMenuService_copy(JNIEnv *env, jobject thiz) {
    iconValid = true;
    const char *cText = copy();
    copy(NULL);
    //Use https://www.base64encode.org/ to encode your image to base64
    return env->NewStringUTF(cText);
}
JNIEXPORT jboolean JNICALL
Java_com_dz_offset_FloatingModMenuService_isCopy(JNIEnv *env, jobject thiz) {

    //Use https://www.base64encode.org/ to encode your image to base64
    return copy() != NULL;
}
JNIEXPORT jstring JNICALL
Java_com_dz_offset_FloatingModMenuService_IconWebViewData(JNIEnv *env, jobject thiz) {
    iconValid = true;
    //WebView support GIF animation. Upload your image or GIF on imgur.com or other sites

    // From internet (Requires android.permission.INTERNET)
    // return env->NewStringUTF(OBFUSCATE("https://i.imgur.com/SujJ85j.gif"));

    // Base64 html:
    // return env->NewStringUTF("data:image/png;base64, <encoded base64 here>");

    // To disable it, return NULL. It will use normal image above:
    // return NULL

    //return env->NewStringUTF(OBFUSCATE_KEY("https://i.imgur.com/SujJ85j.gif", 'u'));
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
Java_com_dz_offset_FloatingModMenuService_settingsList(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_Settings"),
            OBFUSCATE("-1_Toggle_Save feature"), //-1 is checked on Preferences.java
            OBFUSCATE("-3_Toggle_Auto size vertically"),
            OBFUSCATE("Category_Credit"),
            OBFUSCATE("RichTextView_<b>Dev by</b> : <font color='#00FFFF'><b>@dzimmortal</b></font>"),
            OBFUSCATE("RichTextView_<b>Telegram</b> : <font color='#00FFFF'><b>@DeathZoneMod</b></font>"),
			OBFUSCATE("RichTextView_if you want more Featues you need buy paid version 10$ Click CONTANT"),
            OBFUSCATE("-7_ButtonLink_<b>CONTANT</b>_https://t.me/dzimmortaL"),
            OBFUSCATE("Category_Menu"),
            OBFUSCATE("-6_Button_<font color='#00FFFF'>Close settings</font>"),
    };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    settingsValid = true;

    return (ret);
}
}
