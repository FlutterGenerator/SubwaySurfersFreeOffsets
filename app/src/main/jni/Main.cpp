#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
// armeabi-v7a
#include "KittyMemory/MemoryPatch.h"
// arm64-v8a
#include "And64InlineHook/And64InlineHook.hpp"
#include "Menu.h"
#include "NepAU/AutoUpdate.cpp"

using namespace NepSymbol;
#include "Offset.h"
#include <sstream>

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

using namespace std;

std::string int2Hex(unsigned int intVal)
{
    std::string hexStr;

    /// integer value to hex
    std::stringstream sstream;
    sstream << std::hex << intVal;

    hexStr= sstream.str();
    sstream.clear();    //clears out the stream-string

    std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);

    return std::string("0x") + hexStr;
}
const char *AddCopyButton(unsigned int Offset) {
       char const* word = "COPYBUTTON_";
       char const* worb = int2Hex(Offset).c_str();
    
       char *s = new char[strlen(word)+strlen(worb)+1];
       strcpy(s,word);
       strcat(s,worb);
    
        return s;
    }
const char *join(const char *a, const char *b) {
        char buffer[128] = {0};
        sprintf(buffer, "%s %s", a, b);
        return (buffer);
}

void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));
LOGD("TheAddresa: %p", 0x98);

    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
        getAddress();
    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);
    
#if defined(__aarch64__)
#else
#endif

    return NULL;
}
extern "C" {
    
    
JNIEXPORT jobjectArray
JNICALL
Java_com_dz_offset_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    
    jobjectArray ret;

    MakeToast(env, context, OBFUSCATE("Free Version Dumper"), Toast::LENGTH_LONG);
    const char *features[] = {
      
        OBFUSCATE("Category_FREE VERSION"), //Not counted
        
        OBFUSCATE("RichTextView_<b>GetCurrency</b> - >>"),
        AddCopyButton(_GetCurrency.getOffset()),
        
        OBFUSCATE("RichTextView_<b>GetGodHack</b> - >>"),
        AddCopyButton(_GetGodHack.getOffset()),
        
        OBFUSCATE("RichTextView_<b>GetGodHack2</b> - >>"),
        AddCopyButton(_GetGodHack2.getOffset()),
        
        OBFUSCATE("RichTextView_<b>getMaxSpeed</b> - >>"),
        AddCopyButton(_getMaxSpeed.getOffset()),
        
        OBFUSCATE("RichTextView_<b>getMinSpeed</b> - >>"),
        AddCopyButton(_getMinSpeed.getOffset()),
        
        OBFUSCATE("RichTextView_<b>getJumpHeight</b> - >>"),
        AddCopyButton(_getJumpHeight.getOffset()),
        
        OBFUSCATE("RichTextView_<b>getJumpLimit</b> - >>"),
        AddCopyButton(_getJumpLimit.getOffset()),
        
        OBFUSCATE("RichTextView_<b>ApplyGravity</b> - >>"),
        AddCopyButton(_ApplyGravity.getOffset()),
		
		OBFUSCATE("RichTextView_<b>UpdateMovement</b> - >>"),
        AddCopyButton(_UpdateMovement.getOffset()),
		
		OBFUSCATE("RichTextView_<b>getownsCoinDoubler</b> - >>"),
        AddCopyButton(_getownsCoinDoubler.getOffset()),
        
		OBFUSCATE("RichTextView_<b>IsAutoReviveEnabled</b> - >>"),
        AddCopyButton(_IsAutoReviveEnabled.getOffset()),
		
		OBFUSCATE("RichTextView_<b>getBaseMultiplierSum</b> - >>"),
        AddCopyButton(_getBaseMultiplierSum.getOffset()),
		
		OBFUSCATE("RichTextView_<b>getLaneChangeDuration</b> - >>"),
        AddCopyButton(_getLaneChangeDuration.getOffset()),
		
		OBFUSCATE("RichTextView_<b>CameraFollow</b> - >>"),
        AddCopyButton(_CameraFollow.getOffset()),
		
		OBFUSCATE("RichTextView_<b>CameraStop</b> - >>"),
        AddCopyButton(_CameraStop.getOffset()),
		
        //ButtonLink
		OBFUSCATE("RichTextView_<font color='#00FAFA'><b>KEEP SUPPORTING</b></font> - >>"),
        OBFUSCATE("ButtonLink_<b>TELEGRAM</b>_https://t.me/DeathZoneMod"),
		OBFUSCATE("ButtonLink_<b>YOUTUBE</b>_https://www.youtube.com/@DeathZoneMod"),
        
        };
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_com_dz_offset_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");
    }
}
__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

