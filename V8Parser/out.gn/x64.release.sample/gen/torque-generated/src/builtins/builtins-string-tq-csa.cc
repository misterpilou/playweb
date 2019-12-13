#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "torque-generated/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-find-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-map-tq-csa.h"
#include "torque-generated/src/builtins/array-of-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-some-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/bigint-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/console-tq-csa.h"
#include "torque-generated/src/builtins/data-view-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-tq-csa.h"
#include "torque-generated/src/builtins/reflect-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/src/builtins/string-html-tq-csa.h"
#include "torque-generated/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/src/builtins/symbol-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"
#include "torque-generated/src/objects/cell-tq-csa.h"
#include "torque-generated/src/objects/code-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/data-handler-tq-csa.h"
#include "torque-generated/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/foreign-tq-csa.h"
#include "torque-generated/src/objects/free-space-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/heap-object-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-collection-tq-csa.h"
#include "torque-generated/src/objects/js-generator-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/microtask-tq-csa.h"
#include "torque-generated/src/objects/module-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/oddball-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-array-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/script-tq-csa.h"
#include "torque-generated/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/src/objects/template-objects-tq-csa.h"
#include "torque-generated/src/objects/template-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(StringPrototypeToString, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToThisValue(TNode<Context>{tmp0}, TNode<Object>{tmp1}, PrimitiveType::kString, "String.prototype.toString");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(StringPrototypeValueOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToThisValue(TNode<Context>{tmp0}, TNode<Object>{tmp1}, PrimitiveType::kString, "String.prototype.valueOf");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(StringToList, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<String> parameter1 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, IntPtrT, NativeContext, Map, JSArray, FixedArray, Smi, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp1});
    TNode<NativeContext> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadJSArrayElementsMap(PACKED_ELEMENTS, TNode<NativeContext>{tmp3});
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp2});
    TNode<JSArray> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).AllocateJSArray(PACKED_ELEMENTS, TNode<Map>{tmp4}, TNode<IntPtrT>{tmp2}, TNode<Smi>{tmp5}, CodeStubAssembler::kAllowLargeObjectAllocation);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp7);
    TNode<FixedArrayBase>tmp8 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<FixedArray> tmp9;
    USE(tmp9);
    tmp9 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp8});
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp9, tmp10, tmp11);
  }

  if (block3.is_used()) {
    TNode<Context> tmp12;
    TNode<String> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<NativeContext> tmp15;
    TNode<Map> tmp16;
    TNode<JSArray> tmp17;
    TNode<FixedArray> tmp18;
    TNode<Smi> tmp19;
    TNode<IntPtrT> tmp20;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp14});
    ca_.Branch(tmp21, &block1, &block2, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20);
  }

  if (block1.is_used()) {
    TNode<Context> tmp22;
    TNode<String> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<NativeContext> tmp25;
    TNode<Map> tmp26;
    TNode<JSArray> tmp27;
    TNode<FixedArray> tmp28;
    TNode<Smi> tmp29;
    TNode<IntPtrT> tmp30;
    ca_.Bind(&block1, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<Int32T> tmp31;
    USE(tmp31);
    tmp31 = StringBuiltinsAssembler(state_).LoadSurrogatePairAt(TNode<String>{tmp23}, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp30}, UnicodeEncoding::UTF16);
    TNode<String> tmp32;
    USE(tmp32);
    tmp32 = StringBuiltinsAssembler(state_).StringFromSingleUTF16EncodedCodePoint(TNode<Int32T>{tmp31});
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp28}, TNode<Smi>{tmp29}, TNode<Object>{tmp32});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp32});
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp33});
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp29}, TNode<Smi>{tmp35});
    ca_.Goto(&block3, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp36, tmp34);
  }

  if (block2.is_used()) {
    TNode<Context> tmp37;
    TNode<String> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<NativeContext> tmp40;
    TNode<Map> tmp41;
    TNode<JSArray> tmp42;
    TNode<FixedArray> tmp43;
    TNode<Smi> tmp44;
    TNode<IntPtrT> tmp45;
    ca_.Bind(&block2, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<IntPtrT> tmp46 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp46);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp42, tmp46}, tmp44);
    CodeStubAssembler(state_).Return(tmp42);
  }

  if (block7.is_used()) {
    TNode<Context> tmp47;
    TNode<String> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<NativeContext> tmp50;
    TNode<Map> tmp51;
    TNode<JSArray> tmp52;
    TNode<FixedArray> tmp53;
    TNode<Smi> tmp54;
    TNode<IntPtrT> tmp55;
    ca_.Bind(&block7, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    CodeStubAssembler(state_).FailAssert("Torque assert 'arrayLength >= 0' failed", "src/builtins/builtins-string.tq", 53);
  }

  if (block6.is_used()) {
    TNode<Context> tmp56;
    TNode<String> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<NativeContext> tmp59;
    TNode<Map> tmp60;
    TNode<JSArray> tmp61;
    TNode<FixedArray> tmp62;
    TNode<Smi> tmp63;
    TNode<IntPtrT> tmp64;
    ca_.Bind(&block6, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
  }

  if (block11.is_used()) {
    TNode<Context> tmp65;
    TNode<String> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<NativeContext> tmp68;
    TNode<Map> tmp69;
    TNode<JSArray> tmp70;
    TNode<FixedArray> tmp71;
    TNode<Smi> tmp72;
    TNode<IntPtrT> tmp73;
    ca_.Bind(&block11, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    CodeStubAssembler(state_).FailAssert("Torque assert 'SmiTag(stringLength) >= arrayLength' failed", "src/builtins/builtins-string.tq", 54);
  }

  if (block10.is_used()) {
    TNode<Context> tmp74;
    TNode<String> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<NativeContext> tmp77;
    TNode<Map> tmp78;
    TNode<JSArray> tmp79;
    TNode<FixedArray> tmp80;
    TNode<Smi> tmp81;
    TNode<IntPtrT> tmp82;
    ca_.Bind(&block10, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
  }
}

void GenerateStringAt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_position, const char* p_methodName, compiler::CodeAssemblerLabel* label_IfInBounds, compiler::TypedCodeAssemblerVariable<String>* label_IfInBounds_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfInBounds_parameter_1, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfInBounds_parameter_2, compiler::CodeAssemblerLabel* label_IfOutOfBounds) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, Smi, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, Smi, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, HeapNumber> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Number, Number, HeapNumber> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_position);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<String> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp2}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<Smi> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_Smi_0(state_, TNode<Object>{tmp5}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp5, tmp5, tmp5, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp4, tmp5, tmp5, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<String> tmp10;
    TNode<Number> tmp11;
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<String> tmp17;
    TNode<Number> tmp18;
    TNode<Number> tmp19;
    TNode<Number> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<UintPtrT> tmp22;
    USE(tmp22);
    tmp22 = LoadStringLengthAsUintPtr_0(state_, TNode<String>{tmp17});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp21});
    TNode<UintPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp23});
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprUintPtrLessThan(String::kMaxLength, kSmiMaxValue)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp25});
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp24}, TNode<UintPtrT>{tmp22});
    ca_.Branch(tmp26, &block7, &block8, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp21, tmp22, tmp24);
  }

  if (block7.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<String> tmp30;
    TNode<Number> tmp31;
    TNode<Number> tmp32;
    TNode<Smi> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<UintPtrT> tmp35;
    ca_.Bind(&block7, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    ca_.Goto(&block2);
  }

  if (block8.is_used()) {
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<String> tmp39;
    TNode<Number> tmp40;
    TNode<Number> tmp41;
    TNode<Smi> tmp42;
    TNode<UintPtrT> tmp43;
    TNode<UintPtrT> tmp44;
    ca_.Bind(&block8, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    *label_IfInBounds_parameter_2 = tmp43;
    *label_IfInBounds_parameter_1 = tmp44;
    *label_IfInBounds_parameter_0 = tmp39;
    ca_.Goto(label_IfInBounds);
  }

  if (block12.is_used()) {
    TNode<Context> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<String> tmp48;
    TNode<Number> tmp49;
    TNode<Number> tmp50;
    TNode<HeapNumber> tmp51;
    ca_.Bind(&block12, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(indexHeapNumber)' failed", "src/builtins/builtins-string.tq", 86);
  }

  if (block11.is_used()) {
    TNode<Context> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<String> tmp55;
    TNode<Number> tmp56;
    TNode<Number> tmp57;
    TNode<HeapNumber> tmp58;
    ca_.Bind(&block11, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(label_IfOutOfBounds);
  }
}

TF_BUILTIN(StringPrototypeCharAt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kPosition));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, String, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    compiler::TypedCodeAssemblerVariable<String> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    GenerateStringAt_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2}, "String.prototype.charAt", &label0, &result_0_0, &result_0_1, &result_0_2, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<NativeContext> tmp8;
    TNode<String> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Int32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp9}, TNode<UintPtrT>{tmp10});
    TNode<String> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Int32T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    ca_.Bind(&block6, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<String> tmp20;
    USE(tmp20);
    tmp20 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp20);
  }
}

TF_BUILTIN(StringPrototypeCharCodeAt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kPosition));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, String, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    compiler::TypedCodeAssemblerVariable<String> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    GenerateStringAt_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2}, "String.prototype.charCodeAt", &label0, &result_0_0, &result_0_1, &result_0_2, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<NativeContext> tmp8;
    TNode<String> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Int32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp9}, TNode<UintPtrT>{tmp10});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    ca_.Bind(&block6, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<HeapNumber> tmp20;
    USE(tmp20);
    tmp20 = kNaN_0(state_);
    CodeStubAssembler(state_).Return(tmp20);
  }
}

TF_BUILTIN(StringPrototypeCodePointAt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kPosition));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, String, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    compiler::TypedCodeAssemblerVariable<String> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    GenerateStringAt_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2}, "String.prototype.codePointAt", &label0, &result_0_0, &result_0_1, &result_0_2, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<NativeContext> tmp8;
    TNode<String> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp11});
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp10});
    TNode<Int32T> tmp14;
    USE(tmp14);
    tmp14 = StringBuiltinsAssembler(state_).LoadSurrogatePairAt(TNode<String>{tmp9}, TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp13}, UnicodeEncoding::UTF32);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp14});
    CodeStubAssembler(state_).Return(tmp15);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<NativeContext> tmp21;
    ca_.Bind(&block6, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Oddball> tmp22;
    USE(tmp22);
    tmp22 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp22);
  }
}

TF_BUILTIN(StringPrototypeConcat, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, String, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, String, IntPtrT, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, String, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.concat");
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<String>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp7, tmp8);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<NativeContext> tmp12;
    TNode<Object> tmp13;
    TNode<String> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp17, &block1, &block2, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<NativeContext> tmp21;
    TNode<Object> tmp22;
    TNode<String> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    ca_.Bind(&block1, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Object> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp18}, TNode<RawPtrT>{tmp19}, TNode<IntPtrT>{tmp20}}, TNode<IntPtrT>{tmp25});
    TNode<String> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp21}, TNode<Object>{tmp26});
    TNode<String> tmp28;
    USE(tmp28);
    tmp28 = StringAdd_0(state_, TNode<Context>{tmp21}, TNode<String>{tmp23}, TNode<String>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp29});
    ca_.Goto(&block3, tmp18, tmp19, tmp20, tmp21, tmp22, tmp28, tmp24, tmp30);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<String> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    arguments.PopAndReturn(tmp36);
  }
}

TF_BUILTIN(StringConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kJSNewTarget));
USE(parameter2);
  TNode<JSFunction> parameter3 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String, Object, Object, NativeContext> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String, Object, Object, NativeContext, Symbol> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSFunction, IntPtrT, String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8});
    ca_.Branch(tmp9, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, ca_.Uninitialized<String>());
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<JSFunction> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<String> tmp18;
    ca_.Bind(&block1, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<String> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).EmptyStringConstant();
    ca_.Goto(&block3, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp19);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<JSFunction> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<String> tmp28;
    ca_.Bind(&block2, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Oddball> tmp29;
    USE(tmp29);
    tmp29 = Undefined_0(state_);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp25}, TNode<HeapObject>{tmp29});
    ca_.Branch(tmp30, &block4, &block5, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<JSFunction> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<String> tmp39;
    ca_.Bind(&block4, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp31}, TNode<RawPtrT>{tmp32}, TNode<IntPtrT>{tmp33}}, TNode<IntPtrT>{tmp40});
    TNode<Symbol> tmp42;
    USE(tmp42);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp42 = Cast_Symbol_1(state_, TNode<Context>{tmp34}, TNode<Object>{tmp41}, &label0);
    ca_.Goto(&block8, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp41, tmp41, tmp34, tmp42);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp41, tmp41, tmp34);
    }
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<JSFunction> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<String> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<NativeContext> tmp54;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Goto(&block5, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp55;
    TNode<RawPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<NativeContext> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<JSFunction> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<String> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<NativeContext> tmp66;
    TNode<Symbol> tmp67;
    ca_.Bind(&block8, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<String> tmp68;
    tmp68 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kSymbolDescriptiveString, tmp58, tmp67)); 
    USE(tmp68);
    arguments.PopAndReturn(tmp68);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<JSFunction> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<String> tmp77;
    ca_.Bind(&block5, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp69}, TNode<RawPtrT>{tmp70}, TNode<IntPtrT>{tmp71}}, TNode<IntPtrT>{tmp78});
    TNode<String> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp72}, TNode<Object>{tmp79});
    ca_.Goto(&block3, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp80);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp81;
    TNode<RawPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<NativeContext> tmp84;
    TNode<Object> tmp85;
    TNode<Object> tmp86;
    TNode<JSFunction> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<String> tmp89;
    ca_.Bind(&block3, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<Oddball> tmp90;
    USE(tmp90);
    tmp90 = Undefined_0(state_);
    TNode<BoolT> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp86}, TNode<HeapObject>{tmp90});
    ca_.Branch(tmp91, &block10, &block11, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp92;
    TNode<RawPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<NativeContext> tmp95;
    TNode<Object> tmp96;
    TNode<Object> tmp97;
    TNode<JSFunction> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<String> tmp100;
    ca_.Bind(&block10, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    arguments.PopAndReturn(tmp100);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp101;
    TNode<RawPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<NativeContext> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<JSFunction> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<String> tmp109;
    ca_.Bind(&block11, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109);
    TNode<JSReceiver> tmp110;
    USE(tmp110);
    tmp110 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp104}, TNode<Object>{tmp106});
    TNode<Map> tmp111;
    USE(tmp111);
    tmp111 = GetDerivedMap_0(state_, TNode<Context>{tmp104}, TNode<JSFunction>{tmp107}, TNode<JSReceiver>{tmp110});
    TNode<JSObject> tmp112;
    USE(tmp112);
    tmp112 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{tmp104}, TNode<Map>{tmp111});
    TNode<JSPrimitiveWrapper> tmp113;
    USE(tmp113);
    tmp113 = UnsafeCast_JSPrimitiveWrapper_0(state_, TNode<Context>{tmp104}, TNode<Object>{tmp112});
    TNode<IntPtrT> tmp114 = ca_.IntPtrConstant(JSPrimitiveWrapper::kValueOffset);
    USE(tmp114);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp113, tmp114}, tmp109);
    arguments.PopAndReturn(tmp113);
  }
}

TF_BUILTIN(StringAddConvertLeft, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<String> parameter2 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = ToPrimitiveDefault_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = ToStringImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = StringAdd_0(state_, TNode<Context>{tmp0}, TNode<String>{tmp4}, TNode<String>{tmp2});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(StringAddConvertRight, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<String> parameter1 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = ToPrimitiveDefault_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = ToStringImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = StringAdd_0(state_, TNode<Context>{tmp0}, TNode<String>{tmp1}, TNode<String>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(StringCharAt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<String> parameter1 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, String, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp1}, TNode<UintPtrT>{tmp2});
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Int32T>{tmp3});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TNode<IntPtrT> Convert_intptr_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<IntPtrT>{tmp2};
}

TNode<Symbol> Cast_Symbol_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Symbol> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_Symbol_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<Symbol> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Symbol> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<Symbol>{tmp20};
}

}  // namespace internal
}  // namespace v8

