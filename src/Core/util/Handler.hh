//
// Copyright (c) 2001,2002                        RIPE NCC
//
// All Rights Reserved
//
// Permission to use, copy, modify, and distribute this software and its
// documentation for any purpose and without fee is hereby granted,
// provided that the above copyright notice appear in all copies and that
// both that copyright notice and this permission notice appear in
// supporting documentation, and that the name of the author not be
// used in advertising or publicity pertaining to distribution of the
// software without specific, written prior permission.
//
// THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
// ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS; IN NO EVENT SHALL
// AUTHOR BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
// AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// $Id$
//
// Handler.hh
// Author(s): Ramesh Govindan

#ifndef _Handler_hh
#define _Handler_hh

// Functions for handling timer and file events are written
// in C, and stored as function pointers in a Handler object.
// The Handler object is syntactic sugar around a function pointer.
// Handler functions take two (opaque to the Handler object)
// arguments:
//	- the first is a pointer to the object which is the target
//		of the callback
//	- the second is an (optional argument) to the handler.

typedef void (*CallBackFunc)(void*, void*);

class Handler {
  public:
    // Create an empty handler
    Handler() {
        function = (CallBackFunc)NULL;
        opaquePtr = (void *)NULL;
    }
    
    // Create a new handler
    Handler(CallBackFunc f,
            void* ptr) {
        function = f;
        opaquePtr= ptr;
    }

    // Destroy handler
    ~Handler() {
        function = (CallBackFunc)NULL;
        opaquePtr = (void *)NULL;
    }

    // Is handler Null?
    bool
    null() const {
        return (function == NULL);
    }
    
    // Assign h to us
    void
    operator=(const Handler& h) {
        function = h.function;
        opaquePtr = h.opaquePtr;
    }

    // Perform the callback
    void
    callBack(void* opaqueArg) const {
        if (function) {
            (*function)(opaquePtr, opaqueArg);
        }
    }

  private:
    CallBackFunc function;
    void*	 opaquePtr;
};

// 
//  Copyright (c) 1994 by the University of Southern California.
//  All rights reserved.
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in
//    all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//    THE SOFTWARE.
//
//  Questions concerning this software should be directed to 
//  irrtoolset@cs.usc.edu.
//
//  Author(s): Ramesh Govindan <govindan@isi.edu>

#endif // _Handler_hh
