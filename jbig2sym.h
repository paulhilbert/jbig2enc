// Copyright 2006 Google Inc. All Rights Reserved.
// Author: agl@imperialviolet.org (Adam Langley)
//
// Copyright (C) 2006 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef JBIG2ENC_JBIG2SYM_H__
#define JBIG2ENC_JBIG2SYM_H__

struct jbig2enc_ctx;

// -----------------------------------------------------------------------------
// Write a symbol table.
//
// symbols: A 2d array. The first dimention is of different classes of symbols.
//          Then, for each class, there are all the examples of that class. The
//          first member of the class is taken as the exemplar.
// symmap: an empty map which is filled. The symbols are written to the file in
//         a different order than they are given in symbols. The maps an index
//         into the symbols array to a symbol number in the file
// -----------------------------------------------------------------------------
void jbig2enc_symboltable(struct jbig2enc_ctx *__restrict__ ctx,
                          PIXAA *__restrict__ const symbols,
                          std::map<int, int> *symmap);

// -----------------------------------------------------------------------------
// Write a text region.
//
// A text region is a list of placements of symbols. The symbols must already
// have been coded.
//
// symmap: This maps class numbers to symbol numbers. Only symbol number appear
//         in the JBIG2 data stream
// boxes: This is an array of positions of symbols on the page
// symbols: (see _symboltable, above)
// assignments: an array, of the same length as boxes, mapping each box to a
//              symbol
// stripwidth: 1 is a safe default (one of [1, 2, 4, 8])
// symbits: number of bits needed to code the symbol number (log2(number of
//          symbols) - rounded up)
// -----------------------------------------------------------------------------
void jbig2enc_textregion(struct jbig2enc_ctx *__restrict__ ctx,
                         /*const*/ std::map<int, int> &symmap,
                         const BOXA *const boxes, const PIXAA *const symbols,
                         NUMA *assignments, int stripwidth, int symbits);

#endif  // JBIG2ENC_JBIG2SYM_H__