package com.jni.myapplication

import android.util.Log

/**
 * Created by CheRevir on 2021/2/1
 */
class Test(value: Int) {
    val value = 10L
    val v: Int

    init {
        Log.e("TAG", "Test -> : Value=$value")
        v = value
    }

    private fun print(value: Long) {
        Log.e("TAG", "Test -> print: $value")
    }
}