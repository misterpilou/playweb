#ifndef V8_GEN_TORQUE_GENERATED_BUILTIN_DEFINITIONS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_BUILTIN_DEFINITIONS_TQ_H_


#define BUILTIN_LIST_FROM_TORQUE(CPP, TFJ, TFC, TFS, TFH, ASM) \
TFJ(ArrayPrototypeCopyWithin, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayEveryLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kThisArg, kInitialK, kLength) \
TFJ(ArrayEveryLoopLazyDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kInitialK, kLength, kResult) \
TFC(ArrayEveryLoopContinuation, ArrayEveryLoopContinuation) \
TFJ(ArrayEvery, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayFilterLoopEagerDeoptContinuation, 6, kReceiver, kCallback, kThisArg, kArray, kInitialK, kLength, kInitialTo) \
TFJ(ArrayFilterLoopLazyDeoptContinuation, 8, kReceiver, kCallback, kThisArg, kArray, kInitialK, kLength, kValueK, kInitialTo, kResult) \
TFC(ArrayFilterLoopContinuation, ArrayFilterLoopContinuation) \
TFJ(ArrayFilter, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayFindLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kThisArg, kInitialK, kLength) \
TFJ(ArrayFindLoopLazyDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kInitialK, kLength, kResult) \
TFJ(ArrayFindLoopAfterCallbackLazyDeoptContinuation, 6, kReceiver, kCallback, kThisArg, kInitialK, kLength, kFoundValue, kIsFound) \
TFC(ArrayFindLoopContinuation, ArrayFindLoopContinuation) \
TFJ(ArrayPrototypeFind, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayFindIndexLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kThisArg, kInitialK, kLength) \
TFJ(ArrayFindIndexLoopLazyDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kInitialK, kLength, kResult) \
TFJ(ArrayFindIndexLoopAfterCallbackLazyDeoptContinuation, 6, kReceiver, kCallback, kThisArg, kInitialK, kLength, kFoundValue, kIsFound) \
TFC(ArrayFindIndexLoopContinuation, ArrayFindIndexLoopContinuation) \
TFJ(ArrayPrototypeFindIndex, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayForEachLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kThisArg, kInitialK, kLength) \
TFJ(ArrayForEachLoopLazyDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kInitialK, kLength, kResult) \
TFC(ArrayForEachLoopContinuation, ArrayForEachLoopContinuation) \
TFJ(ArrayForEach, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayIsArray, 1, kReceiver, kArg) \
TFC(LoadJoinElement_DictionaryElements_0, LoadJoinElement_DictionaryElements_0) \
TFC(LoadJoinElement_FastSmiOrObjectElements_0, LoadJoinElement_FastSmiOrObjectElements_0) \
TFC(LoadJoinElement_FastDoubleElements_0, LoadJoinElement_FastDoubleElements_0) \
TFC(ConvertToLocaleString, ConvertToLocaleString) \
TFC(JoinStackPush, JoinStackPush) \
TFC(JoinStackPop, JoinStackPop) \
TFJ(ArrayPrototypeJoin, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeToLocaleString, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeToString, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeJoin, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeToLocaleString, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeLastIndexOf, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayMapLoopEagerDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kArray, kInitialK, kLength) \
TFJ(ArrayMapLoopLazyDeoptContinuation, 6, kReceiver, kCallback, kThisArg, kArray, kInitialK, kLength, kResult) \
TFC(ArrayMapLoopContinuation, ArrayMapLoopContinuation) \
TFJ(ArrayMap, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayOf, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayReduceRightPreLoopEagerDeoptContinuation, 2, kReceiver, kCallback, kLength) \
TFJ(ArrayReduceRightLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kInitialK, kLength, kAccumulator) \
TFJ(ArrayReduceRightLoopLazyDeoptContinuation, 4, kReceiver, kCallback, kInitialK, kLength, kResult) \
TFC(ArrayReduceRightLoopContinuation, ArrayReduceRightLoopContinuation) \
TFJ(ArrayReduceRight, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayReducePreLoopEagerDeoptContinuation, 2, kReceiver, kCallback, kLength) \
TFJ(ArrayReduceLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kInitialK, kLength, kAccumulator) \
TFJ(ArrayReduceLoopLazyDeoptContinuation, 4, kReceiver, kCallback, kInitialK, kLength, kResult) \
TFC(ArrayReduceLoopContinuation, ArrayReduceLoopContinuation) \
TFJ(ArrayReduce, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeReverse, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeShift, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeSlice, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArraySomeLoopEagerDeoptContinuation, 4, kReceiver, kCallback, kThisArg, kInitialK, kLength) \
TFJ(ArraySomeLoopLazyDeoptContinuation, 5, kReceiver, kCallback, kThisArg, kInitialK, kLength, kResult) \
TFC(ArraySomeLoopContinuation, ArraySomeLoopContinuation) \
TFJ(ArraySome, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeSplice, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ArrayPrototypeUnshift, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(ToString, ToString) \
TFC(FastCreateDataProperty, FastCreateDataProperty) \
TFC(CheckNumberInRange, CheckNumberInRange) \
TFC(BigIntAddNoThrow, BigIntAddNoThrow) \
TFC(BigIntAdd, BigIntAdd) \
TFC(BigIntSubtractNoThrow, BigIntSubtractNoThrow) \
TFC(BigIntSubtract, BigIntSubtract) \
TFC(BigIntUnaryMinus, BigIntUnaryMinus) \
TFJ(BooleanConstructor, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(BooleanPrototypeToString, 0, kReceiver) \
TFJ(BooleanPrototypeValueOf, 0, kReceiver) \
TFJ(StringPrototypeToString, 0, kReceiver) \
TFJ(StringPrototypeValueOf, 0, kReceiver) \
TFC(StringToList, StringToList) \
TFJ(StringPrototypeCharAt, 1, kReceiver, kPosition) \
TFJ(StringPrototypeCharCodeAt, 1, kReceiver, kPosition) \
TFJ(StringPrototypeCodePointAt, 1, kReceiver, kPosition) \
TFJ(StringPrototypeConcat, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringConstructor, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(StringAddConvertLeft, StringAddConvertLeft) \
TFC(StringAddConvertRight, StringAddConvertRight) \
TFC(StringCharAt, StringCharAt) \
TFJ(FastConsoleAssert, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetBuffer, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetByteLength, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetByteOffset, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetUint8, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetInt8, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetUint16, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetInt16, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetUint32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetInt32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetFloat32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetFloat64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetBigUint64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeGetBigInt64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetUint8, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetInt8, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetUint16, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetInt16, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetUint32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetInt32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetFloat32, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetFloat64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetBigUint64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(DataViewPrototypeSetBigInt64, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(IncBlockCounter, IncBlockCounter) \
TFC(GetIteratorWithFeedback, GetIteratorWithFeedback) \
TFC(CallIteratorWithFeedback, CallIteratorWithFeedback) \
TFJ(MathAbs, 1, kReceiver, kX) \
TFJ(MathCeil, 1, kReceiver, kX) \
TFJ(MathFloor, 1, kReceiver, kX) \
TFJ(MathRound, 1, kReceiver, kX) \
TFJ(MathTrunc, 1, kReceiver, kX) \
TFJ(MathPow, 2, kReceiver, kBase, kExponent) \
TFJ(MathMax, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(MathMin, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(MathAcos, 1, kReceiver, kX) \
TFJ(MathAcosh, 1, kReceiver, kX) \
TFJ(MathAsin, 1, kReceiver, kX) \
TFJ(MathAsinh, 1, kReceiver, kX) \
TFJ(MathAtan, 1, kReceiver, kX) \
TFJ(MathAtan2, 2, kReceiver, kY, kX) \
TFJ(MathAtanh, 1, kReceiver, kX) \
TFJ(MathCbrt, 1, kReceiver, kX) \
TFJ(MathClz32, 1, kReceiver, kX) \
TFJ(MathCos, 1, kReceiver, kX) \
TFJ(MathCosh, 1, kReceiver, kX) \
TFJ(MathExp, 1, kReceiver, kX) \
TFJ(MathExpm1, 1, kReceiver, kX) \
TFJ(MathFround, 1, kReceiver, kX) \
TFJ(MathImul, 2, kReceiver, kX, kY) \
TFJ(MathLog, 1, kReceiver, kX) \
TFJ(MathLog1p, 1, kReceiver, kX) \
TFJ(MathLog10, 1, kReceiver, kX) \
TFJ(MathLog2, 1, kReceiver, kX) \
TFJ(MathSin, 1, kReceiver, kX) \
TFJ(MathSign, 1, kReceiver, kX) \
TFJ(MathSinh, 1, kReceiver, kX) \
TFJ(MathSqrt, 1, kReceiver, kX) \
TFJ(MathTan, 1, kReceiver, kX) \
TFJ(MathTanh, 1, kReceiver, kX) \
TFJ(MathHypot, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(MathRandom, 0, kReceiver) \
TFJ(NumberPrototypeToString, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ObjectFromEntries, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(CreateObjectWithoutProperties, CreateObjectWithoutProperties) \
TFJ(ObjectIsExtensible, 1, kReceiver, kObject) \
TFJ(ObjectPreventExtensions, 1, kReceiver, kObject) \
TFJ(ObjectGetPrototypeOf, 1, kReceiver, kObject) \
TFJ(ObjectSetPrototypeOf, 2, kReceiver, kObject, kProto) \
TFC(FulfillPromise, FulfillPromise) \
TFC(RejectPromise, RejectPromise) \
TFC(NewPromiseCapability, NewPromiseCapability) \
TFJ(PromiseCapabilityDefaultReject, 1, kReceiver, kReason) \
TFJ(PromiseCapabilityDefaultResolve, 1, kReceiver, kResolution) \
TFC(PerformPromiseThen, PerformPromiseThen) \
TFJ(PromiseConstructor, 1, kReceiver, kExecutor) \
TFJ(ProxyConstructor, 2, kReceiver, kTarget, kHandler) \
TFC(ProxyDeleteProperty, ProxyDeleteProperty) \
TFC(ProxyGetProperty, ProxyGetProperty) \
TFC(ProxyGetPrototypeOf, ProxyGetPrototypeOf) \
TFC(ProxyHasProperty, ProxyHasProperty) \
TFC(ProxyIsExtensible, ProxyIsExtensible) \
TFC(ProxyPreventExtensions, ProxyPreventExtensions) \
TFJ(ProxyRevocable, 2, kReceiver, kTarget, kHandler) \
TFJ(ProxyRevoke, 0, kReceiver) \
TFC(ProxySetProperty, ProxySetProperty) \
TFC(ProxySetPrototypeOf, ProxySetPrototypeOf) \
TFJ(ReflectIsExtensible, 1, kReceiver, kObject) \
TFJ(ReflectPreventExtensions, 1, kReceiver, kObject) \
TFJ(ReflectGetPrototypeOf, 1, kReceiver, kObject) \
TFJ(ReflectSetPrototypeOf, 2, kReceiver, kObject, kProto) \
TFJ(ReflectGet, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(ReflectDeleteProperty, 2, kReceiver, kObject, kKey) \
TFJ(ReflectHas, 2, kReceiver, kObject, kKey) \
TFC(RegExpPrototypeExecSlow, RegExpPrototypeExecSlow) \
TFJ(RegExpPrototypeExec, 1, kReceiver, kString) \
TFJ(RegExpPrototypeMatchAll, 1, kReceiver, kString) \
TFJ(RegExpStringIteratorPrototypeNext, 0, kReceiver) \
TFC(RegExpMatchFast, RegExpMatchFast) \
TFJ(RegExpPrototypeMatch, 1, kReceiver, kString) \
TFC(RegExpReplace, RegExpReplace) \
TFJ(RegExpPrototypeReplace, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(RegExpSearchFast, RegExpSearchFast) \
TFJ(RegExpPrototypeSearch, 1, kReceiver, kString) \
TFJ(RegExpPrototypeSourceGetter, 0, kReceiver) \
TFC(RegExpSplit, RegExpSplit) \
TFJ(RegExpPrototypeSplit, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(RegExpPrototypeTest, 1, kReceiver, kString) \
TFC(RegExpPrototypeTestFast, RegExpPrototypeTestFast) \
TFJ(RegExpPrototypeGlobalGetter, 0, kReceiver) \
TFJ(RegExpPrototypeIgnoreCaseGetter, 0, kReceiver) \
TFJ(RegExpPrototypeMultilineGetter, 0, kReceiver) \
TFJ(RegExpPrototypeDotAllGetter, 0, kReceiver) \
TFJ(RegExpPrototypeStickyGetter, 0, kReceiver) \
TFJ(RegExpPrototypeUnicodeGetter, 0, kReceiver) \
TFJ(RegExpPrototypeFlagsGetter, 0, kReceiver) \
TFJ(StringPrototypeEndsWith, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(CreateHTML, CreateHTML) \
TFJ(StringPrototypeAnchor, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeBig, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeBlink, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeBold, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeFontcolor, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeFontsize, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeFixed, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeItalics, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeLink, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeSmall, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeStrike, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeSub, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeSup, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeIterator, 0, kReceiver) \
TFJ(StringIteratorPrototypeNext, 0, kReceiver) \
TFJ(StringPrototypePadStart, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypePadEnd, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(StringRepeat, StringRepeat) \
TFJ(StringPrototypeRepeat, 1, kReceiver, kCount) \
TFJ(StringPrototypeReplaceAll, 2, kReceiver, kSearchValue, kReplaceValue) \
TFJ(StringPrototypeSlice, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeStartsWith, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeSubstring, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(StringPrototypeSubstr, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(SymbolPrototypeDescriptionGetter, 0, kReceiver) \
TFJ(SymbolPrototypeToPrimitive, 1, kReceiver, kHint) \
TFJ(SymbolPrototypeToString, 0, kReceiver) \
TFJ(SymbolPrototypeValueOf, 0, kReceiver) \
TFC(CreateTypedArray, CreateTypedArray) \
TFJ(TypedArrayPrototypeEvery, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeFilter, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeFind, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeFindIndex, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeForEach, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayFrom, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayOf, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeReduce, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeReduceRight, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeSet, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeSlice, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeSome, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(TypedArrayMergeSort, TypedArrayMergeSort) \
TFJ(TypedArrayPrototypeSort, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFJ(TypedArrayPrototypeSubArray, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(GenericBuiltinTest_JSAny_0, GenericBuiltinTest_JSAny_0) \
TFC(TestHelperPlus1, TestHelperPlus1) \
TFC(TestHelperPlus2, TestHelperPlus2) \
TFC(NewSmiBox, NewSmiBox) \
TFC(Load_FastSmiElements_0, Load_FastSmiElements_0) \
TFC(Load_FastObjectElements_0, Load_FastObjectElements_0) \
TFC(Load_FastDoubleElements_0, Load_FastDoubleElements_0) \
TFC(Store_FastSmiElements_0, Store_FastSmiElements_0) \
TFC(Store_FastObjectElements_0, Store_FastObjectElements_0) \
TFC(Store_FastDoubleElements_0, Store_FastDoubleElements_0) \
TFC(Delete_FastSmiElements_0, Delete_FastSmiElements_0) \
TFC(Delete_FastObjectElements_0, Delete_FastObjectElements_0) \
TFC(Delete_FastDoubleElements_0, Delete_FastDoubleElements_0) \
TFC(SortCompareDefault, SortCompareDefault) \
TFC(SortCompareUserFn, SortCompareUserFn) \
TFC(CanUseSameAccessor_GenericElementsAccessor_0, CanUseSameAccessor_GenericElementsAccessor_0) \
TFC(Copy, Copy) \
TFC(MergeAt, MergeAt) \
TFC(GallopLeft, GallopLeft) \
TFC(GallopRight, GallopRight) \
TFC(ArrayTimSort, ArrayTimSort) \
TFJ(ArrayPrototypeSort, SharedFunctionInfo::kDontAdaptArgumentsSentinel) \
TFC(LoadJoinElement_GenericElementsAccessor_0, LoadJoinElement_GenericElementsAccessor_0) \
TFC(LoadJoinTypedElement_Int32Elements_0, LoadJoinTypedElement_Int32Elements_0) \
TFC(LoadJoinTypedElement_Float32Elements_0, LoadJoinTypedElement_Float32Elements_0) \
TFC(LoadJoinTypedElement_Float64Elements_0, LoadJoinTypedElement_Float64Elements_0) \
TFC(LoadJoinTypedElement_Uint8ClampedElements_0, LoadJoinTypedElement_Uint8ClampedElements_0) \
TFC(LoadJoinTypedElement_BigUint64Elements_0, LoadJoinTypedElement_BigUint64Elements_0) \
TFC(LoadJoinTypedElement_BigInt64Elements_0, LoadJoinTypedElement_BigInt64Elements_0) \
TFC(LoadJoinTypedElement_Uint8Elements_0, LoadJoinTypedElement_Uint8Elements_0) \
TFC(LoadJoinTypedElement_Int8Elements_0, LoadJoinTypedElement_Int8Elements_0) \
TFC(LoadJoinTypedElement_Uint16Elements_0, LoadJoinTypedElement_Uint16Elements_0) \
TFC(LoadJoinTypedElement_Int16Elements_0, LoadJoinTypedElement_Int16Elements_0) \
TFC(LoadJoinTypedElement_Uint32Elements_0, LoadJoinTypedElement_Uint32Elements_0) \
TFC(GenericBuiltinTest_Smi_0, GenericBuiltinTest_Smi_0) \
TFC(CanUseSameAccessor_FastDoubleElements_0, CanUseSameAccessor_FastDoubleElements_0) \
TFC(CanUseSameAccessor_FastSmiElements_0, CanUseSameAccessor_FastSmiElements_0) \
TFC(CanUseSameAccessor_FastObjectElements_0, CanUseSameAccessor_FastObjectElements_0) \
TFC(Load_GenericElementsAccessor_0, Load_GenericElementsAccessor_0) \
TFC(Store_GenericElementsAccessor_0, Store_GenericElementsAccessor_0) \
TFC(Delete_GenericElementsAccessor_0, Delete_GenericElementsAccessor_0) \
TFC(LoadTypedElement_Int32Elements_0, LoadTypedElement_Int32Elements_0) \
TFC(StoreTypedElementNumeric_Int32Elements_0, StoreTypedElementNumeric_Int32Elements_0) \
TFC(StoreTypedElementJSAny_Int32Elements_0, StoreTypedElementJSAny_Int32Elements_0) \
TFC(LoadTypedElement_Float32Elements_0, LoadTypedElement_Float32Elements_0) \
TFC(StoreTypedElementNumeric_Float32Elements_0, StoreTypedElementNumeric_Float32Elements_0) \
TFC(StoreTypedElementJSAny_Float32Elements_0, StoreTypedElementJSAny_Float32Elements_0) \
TFC(LoadTypedElement_Float64Elements_0, LoadTypedElement_Float64Elements_0) \
TFC(StoreTypedElementNumeric_Float64Elements_0, StoreTypedElementNumeric_Float64Elements_0) \
TFC(StoreTypedElementJSAny_Float64Elements_0, StoreTypedElementJSAny_Float64Elements_0) \
TFC(LoadTypedElement_Uint8ClampedElements_0, LoadTypedElement_Uint8ClampedElements_0) \
TFC(StoreTypedElementNumeric_Uint8ClampedElements_0, StoreTypedElementNumeric_Uint8ClampedElements_0) \
TFC(StoreTypedElementJSAny_Uint8ClampedElements_0, StoreTypedElementJSAny_Uint8ClampedElements_0) \
TFC(LoadTypedElement_BigUint64Elements_0, LoadTypedElement_BigUint64Elements_0) \
TFC(StoreTypedElementNumeric_BigUint64Elements_0, StoreTypedElementNumeric_BigUint64Elements_0) \
TFC(StoreTypedElementJSAny_BigUint64Elements_0, StoreTypedElementJSAny_BigUint64Elements_0) \
TFC(LoadTypedElement_BigInt64Elements_0, LoadTypedElement_BigInt64Elements_0) \
TFC(StoreTypedElementNumeric_BigInt64Elements_0, StoreTypedElementNumeric_BigInt64Elements_0) \
TFC(StoreTypedElementJSAny_BigInt64Elements_0, StoreTypedElementJSAny_BigInt64Elements_0) \
TFC(LoadTypedElement_Uint8Elements_0, LoadTypedElement_Uint8Elements_0) \
TFC(StoreTypedElementNumeric_Uint8Elements_0, StoreTypedElementNumeric_Uint8Elements_0) \
TFC(StoreTypedElementJSAny_Uint8Elements_0, StoreTypedElementJSAny_Uint8Elements_0) \
TFC(LoadTypedElement_Int8Elements_0, LoadTypedElement_Int8Elements_0) \
TFC(StoreTypedElementNumeric_Int8Elements_0, StoreTypedElementNumeric_Int8Elements_0) \
TFC(StoreTypedElementJSAny_Int8Elements_0, StoreTypedElementJSAny_Int8Elements_0) \
TFC(LoadTypedElement_Uint16Elements_0, LoadTypedElement_Uint16Elements_0) \
TFC(StoreTypedElementNumeric_Uint16Elements_0, StoreTypedElementNumeric_Uint16Elements_0) \
TFC(StoreTypedElementJSAny_Uint16Elements_0, StoreTypedElementJSAny_Uint16Elements_0) \
TFC(LoadTypedElement_Int16Elements_0, LoadTypedElement_Int16Elements_0) \
TFC(StoreTypedElementNumeric_Int16Elements_0, StoreTypedElementNumeric_Int16Elements_0) \
TFC(StoreTypedElementJSAny_Int16Elements_0, StoreTypedElementJSAny_Int16Elements_0) \
TFC(LoadTypedElement_Uint32Elements_0, LoadTypedElement_Uint32Elements_0) \
TFC(StoreTypedElementNumeric_Uint32Elements_0, StoreTypedElementNumeric_Uint32Elements_0) \
TFC(StoreTypedElementJSAny_Uint32Elements_0, StoreTypedElementJSAny_Uint32Elements_0) \

#define TORQUE_FUNCTION_POINTER_TYPE_TO_BUILTIN_MAP(V) \
  V(0,LoadJoinElement_DictionaryElements_0)\
  V(1,LoadTypedElement_Int32Elements_0)\
  V(2,StoreTypedElementNumeric_Int32Elements_0)\
  V(3,StoreTypedElementJSAny_Int32Elements_0)\
  V(4,CreateObjectWithoutProperties)\
  V(5,Load_FastSmiElements_0)\
  V(6,Store_FastSmiElements_0)\
  V(7,Delete_FastSmiElements_0)\
  V(8,CanUseSameAccessor_GenericElementsAccessor_0)\
  V(9,SortCompareDefault)\
  V(10,TestHelperPlus1)\
  V(11,GenericBuiltinTest_Smi_0)\

#endif  // V8_GEN_TORQUE_GENERATED_BUILTIN_DEFINITIONS_TQ_H_
