package com.yukar1z0e.crackqq;

import android.app.Application;
import android.content.Context;
import android.os.FileObserver;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.os.Bundle;
import android.view.ViewGroup;
import android.view.MotionEvent;

import java.text.Format;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.LinkedList;
import java.util.Objects;
import java.util.concurrent.RunnableFuture;
import java.util.concurrent.TimeUnit;

import de.robv.android.xposed.XC_MethodHook;
import de.robv.android.xposed.IXposedHookLoadPackage;
import de.robv.android.xposed.callbacks.XC_LoadPackage;

import static de.robv.android.xposed.XposedHelpers.assetAsByteArray;
import static de.robv.android.xposed.XposedHelpers.findAndHookConstructor;
import static de.robv.android.xposed.XposedHelpers.findClass;
import static de.robv.android.xposed.XposedHelpers.findField;
import static de.robv.android.xposed.XposedHelpers.callMethod;
import static de.robv.android.xposed.XposedHelpers.setObjectField;
import static de.robv.android.xposed.XposedHelpers.findAndHookMethod;

public class crackmain implements IXposedHookLoadPackage {
    private XC_LoadPackage.LoadPackageParam lpparam = null;

    @Override
    public void handleLoadPackage(final XC_LoadPackage.LoadPackageParam loadPackageParam) throws Throwable {
        if (loadPackageParam.packageName.contains("com.tencent")) {
            findAndHookMethod(Application.class, "attach", Context.class, new XC_MethodHook() {
                @Override
                protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                    lpparam = loadPackageParam;
                    getPeerInfo();
                    getAvatar();
                }
            });
        }
    }

    public void getPeerInfo(){
        final Class<?> ProfileActivity$AllInOneClass=findClass("com.tencent.mobileqq.activity.ProfileActivity$AllInOne",lpparam.classLoader);

        findAndHookMethod(ProfileActivity$AllInOneClass, "a", ProfileActivity$AllInOneClass, new XC_MethodHook() {
            @Override
            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                Log.d("crackQQ",param.args[0].toString());
            }
        });
    }

   /*
   Test
   */

    public void getInfo(){
        final Class<?> ProfileActivity$AllInOneClass=findClass("com.tencent.mobileqq.activity.ProfileActivity$AllInOne",lpparam.classLoader);
        final Class<?> ProfileActivity$CardContactInfoClass=findClass("com.tencent.mobileqq.activity.ProfileActivity$CardContactInfo",lpparam.classLoader);

        findAndHookMethod(ProfileActivity$AllInOneClass, "a", ProfileActivity$AllInOneClass, new XC_MethodHook() {
            @Override
            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                Log.d("crackQQ","Crack In AllInOne "+param.args[0]);
                Field[] AllInOneFields=ProfileActivity$AllInOneClass.getDeclaredFields();
                for(Field AllInOneField:AllInOneFields){
                    Log.d("crackQQ","Field Name: "+AllInOneField.getName()+"Field Type: "+AllInOneField.getType()+" Field Value: "+AllInOneField.get(param.args[0]));
                }

                Field Arraylist_field_a=findField(ProfileActivity$AllInOneClass,"a");
                Object Arraylist_object_a=Arraylist_field_a.get(param.args[0]);
                ArrayList list=new ArrayList(1);
                list=(ArrayList)Arraylist_object_a;
                Object a=list.get(0);

                Field CardContactInfoafield=findField(ProfileActivity$CardContactInfoClass,"a");
                Field CardContactInfobfield=findField(ProfileActivity$CardContactInfoClass,"b");
                Field CardContactInfocfield=findField(ProfileActivity$CardContactInfoClass,"c");

                Log.d("crackQQ","a: "+CardContactInfoafield.get(a)+" b: "+CardContactInfobfield.get(a)+" c: "+CardContactInfocfield.get(a));
            }
        });
    }

    public void getAvatar(){
        final Class<?> aClass=findClass("com.tencent.mobileqq.activity.FriendProfileImageAvatar",lpparam.classLoader);
        final Class<?> BaseActivityClass=findClass("com.tencent.mobileqq.app.BaseActivity",lpparam.classLoader);
        final Class<?> ProfileImageInfoClass=findClass("com.tencent.mobileqq.activity.FriendProfileImageModel.ProfileImageInfo",lpparam.classLoader);

        findAndHookMethod(aClass, "a", BaseActivityClass, ProfileImageInfoClass, new XC_MethodHook() {
            @Override
            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                Log.d("crackQQ","I am in again");

                Field[] ProfileImageInfoFields=ProfileImageInfoClass.getDeclaredFields();
                for(Field ProfileImageInfoField:ProfileImageInfoFields){
                    Log.d("crackQQ","Field Name: "+ProfileImageInfoField.getName()+" Field Value: "+ProfileImageInfoField.get(param.args[1]));
                }

                Field c=findField(ProfileImageInfoClass,"c");
                Log.d("crackQQ","Photo Path:"+c.get(param.args[1]).toString());
            }
        });
    }
}
