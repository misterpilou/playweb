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

TNode<JSArray> NewJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<FixedArrayBase> p_elements) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, FixedArrayBase> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, FixedArrayBase, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_elements);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<FixedArrayBase> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrConstant(((16)));
    TNode<JSArray> tmp7;
    USE(tmp7);
    tmp7 = ca_.UncheckedCast<JSArray>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp6}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp7, CodeStubAssembler(state_).IntPtrConstant(16), TNode<IntPtrT>{tmp6}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp8 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp8);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp7, tmp8}, tmp1);
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(JSReceiver::kPropertiesOrHashOffset);
    USE(tmp9);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp7, tmp9}, tmp3);
    TNode<IntPtrT> tmp10 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp10);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp7, tmp10}, tmp2);
    TNode<IntPtrT> tmp11 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp11);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp7, tmp11}, tmp5);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp7);
  }

    TNode<Context> tmp12;
    TNode<Map> tmp13;
    TNode<FixedArrayBase> tmp14;
    TNode<JSArray> tmp15;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15);
  return TNode<JSArray>{tmp15};
}

TNode<JSArray> NewJSArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Map> tmp1;
    USE(tmp1);
    tmp1 = GetFastPackedSmiElementsJSArrayMap_0(state_, TNode<Context>{tmp0});
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IntPtrConstant(((16)));
    TNode<JSArray> tmp5;
    USE(tmp5);
    tmp5 = ca_.UncheckedCast<JSArray>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp4}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp5, CodeStubAssembler(state_).IntPtrConstant(16), TNode<IntPtrT>{tmp4}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp6);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSReceiver::kPropertiesOrHashOffset);
    USE(tmp7);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp7}, tmp2);
    TNode<IntPtrT> tmp8 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp8);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp8}, tmp3);
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp9);
    TNode<Number> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp9}, tmp10);
    ca_.Goto(&block2, tmp0, tmp5);
  }

    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block2, &tmp11, &tmp12);
  return TNode<JSArray>{tmp12};
}

TNode<Object> LoadElementNoHole_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, Object, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArray, Object, Object, Object, Oddball> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp3);
    TNode<FixedArrayBase>tmp4 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<FixedArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<JSArray> tmp7;
    TNode<Smi> tmp8;
    TNode<FixedArrayBase> tmp9;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<FixedArray> tmp14;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp15);
    TNode<IntPtrT> tmp16 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp16);
    TNode<Smi>tmp17 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp16});
    TNode<IntPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp12});
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp20}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp22, &block11, &block12, tmp10, tmp11, tmp12, tmp14, tmp14, tmp15, tmp18, tmp12, tmp12, tmp19, tmp14, tmp15, tmp18, tmp19, tmp19);
  }

  if (block11.is_used()) {
    TNode<Context> tmp23;
    TNode<JSArray> tmp24;
    TNode<Smi> tmp25;
    TNode<FixedArray> tmp26;
    TNode<FixedArray> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<Smi> tmp30;
    TNode<Smi> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    ca_.Bind(&block11, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp39});
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp33}, TNode<IntPtrT>{tmp40}).Flatten();
    TNode<Object>tmp43 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp41, tmp42});
    TNode<Object> tmp44;
    USE(tmp44);
    tmp44 = UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Context>{tmp23}, TNode<Object>{tmp43});
    TNode<Oddball> tmp45;
    USE(tmp45);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp45 = Cast_TheHole_0(state_, TNode<Object>{tmp44}, &label0);
    ca_.Goto(&block16, tmp23, tmp24, tmp25, tmp26, tmp44, tmp44, tmp44, tmp45);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp23, tmp24, tmp25, tmp26, tmp44, tmp44, tmp44);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp46;
    TNode<JSArray> tmp47;
    TNode<Smi> tmp48;
    TNode<FixedArray> tmp49;
    TNode<FixedArray> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<HeapObject> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block12, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<Context> tmp61;
    TNode<JSArray> tmp62;
    TNode<Smi> tmp63;
    TNode<FixedArray> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block17, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    ca_.Goto(&block18, tmp61, tmp62, tmp63, ca_.UncheckedCast<Object>(tmp66));
  }

  if (block16.is_used()) {
    TNode<Context> tmp68;
    TNode<JSArray> tmp69;
    TNode<Smi> tmp70;
    TNode<FixedArray> tmp71;
    TNode<Object> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Oddball> tmp75;
    ca_.Bind(&block16, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    ca_.Goto(label_IfHole);
  }

    TNode<Context> tmp76;
    TNode<JSArray> tmp77;
    TNode<Smi> tmp78;
    TNode<Object> tmp79;
    ca_.Bind(&block18, &tmp76, &tmp77, &tmp78, &tmp79);
  return TNode<Object>{tmp79};
}

TNode<Object> LoadElementNoHole_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedArrayBase, FixedDoubleArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, FixedDoubleArray, FixedDoubleArray, Smi, Float64T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp3);
    TNode<FixedArrayBase>tmp4 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<FixedDoubleArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<JSArray> tmp7;
    TNode<Smi> tmp8;
    TNode<FixedArrayBase> tmp9;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    TNode<Smi> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<FixedDoubleArray> tmp14;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Float64T> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = CodeStubAssembler(state_).LoadDoubleWithHoleCheck(TNode<FixedDoubleArray>{tmp14}, TNode<Smi>{tmp12}, &label0);
    ca_.Goto(&block7, tmp10, tmp11, tmp12, tmp14, tmp14, tmp12, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp10, tmp11, tmp12, tmp14, tmp14, tmp12);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<JSArray> tmp17;
    TNode<Smi> tmp18;
    TNode<FixedDoubleArray> tmp19;
    TNode<FixedDoubleArray> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(label_IfHole);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<JSArray> tmp23;
    TNode<Smi> tmp24;
    TNode<FixedDoubleArray> tmp25;
    TNode<FixedDoubleArray> tmp26;
    TNode<Smi> tmp27;
    TNode<Float64T> tmp28;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<HeapNumber> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp28});
    ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp29);
  }

    TNode<Context> tmp30;
    TNode<JSArray> tmp31;
    TNode<Smi> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block9, &tmp30, &tmp31, &tmp32, &tmp33);
  return TNode<Object>{tmp33};
}

void TorqueMoveElementsSmi_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(HOLEY_SMI_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueMoveElements_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(HOLEY_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueMoveElements_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<IntPtrT> p_dstIndex, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_dstIndex, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).MoveElements(HOLEY_DOUBLE_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<FixedDoubleArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
}

void TorqueCopyElements_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_dstElements, TNode<IntPtrT> p_dstIndex, TNode<FixedArray> p_srcElements, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_dstElements, p_dstIndex, p_srcElements, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<FixedArray> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    CodeStubAssembler(state_).CopyElements(HOLEY_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<FixedArrayBase>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<FixedArray> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<FixedArray> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
}

void TorqueCopyElements_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_dstElements, TNode<IntPtrT> p_dstIndex, TNode<FixedDoubleArray> p_srcElements, TNode<IntPtrT> p_srcIndex, TNode<IntPtrT> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_dstElements, p_dstIndex, p_srcElements, p_srcIndex, p_count);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<FixedDoubleArray> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    CodeStubAssembler(state_).CopyElements(HOLEY_DOUBLE_ELEMENTS, TNode<FixedArrayBase>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<FixedArrayBase>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

    TNode<FixedDoubleArray> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<FixedDoubleArray> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
}

TorqueStructFastJSArrayWitness_0 NewFastJSArrayWitness_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, JSArray, JSArray, Map, BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp1);
    TNode<Map>tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp4);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp3});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IsElementsKindLessThanOrEqual(TNode<Int32T>{tmp3}, HOLEY_SMI_ELEMENTS);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block2, tmp0, tmp0, tmp0, tmp5, tmp6, tmp7, tmp8);
  }

    TNode<JSArray> tmp9;
    TNode<JSArray> tmp10;
    TNode<JSArray> tmp11;
    TNode<Map> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
  return TorqueStructFastJSArrayWitness_0{TNode<JSArray>{tmp10}, TNode<JSArray>{tmp11}, TNode<Map>{tmp12}, TNode<BoolT>{tmp13}, TNode<BoolT>{tmp14}, TNode<BoolT>{tmp15}};
}

TorqueStructFastJSArrayForReadWitness_0 NewFastJSArrayForReadWitness_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, JSArray, JSArray, Map, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp1);
    TNode<Map>tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp4);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp3});
    ca_.Goto(&block2, tmp0, tmp0, tmp0, tmp5, tmp6);
  }

    TNode<JSArray> tmp7;
    TNode<JSArray> tmp8;
    TNode<JSArray> tmp9;
    TNode<Map> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
  return TorqueStructFastJSArrayForReadWitness_0{TNode<JSArray>{tmp8}, TNode<JSArray>{tmp9}, TNode<Map>{tmp10}, TNode<BoolT>{tmp11}};
}

TNode<JSReceiver> LoadJSArrayIteratorIteratedObject_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArrayIterator::kIteratedObjectOffset);
    USE(tmp1);
    TNode<JSReceiver>tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<JSReceiver> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<JSReceiver>{tmp4};
}

void StoreJSArrayIteratorIteratedObject_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<JSReceiver> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<JSReceiver> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSArrayIterator::kIteratedObjectOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<JSReceiver> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadJSArrayIteratorNextIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArrayIterator::kNextIndexOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreJSArrayIteratorNextIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSArrayIterator::kNextIndexOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadJSArrayIteratorKind_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArrayIterator::kKindOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreJSArrayIteratorKind_0(compiler::CodeAssemblerState* state_, TNode<JSArrayIterator> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayIterator, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArrayIterator> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSArrayIterator::kKindOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArrayIterator> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<JSArray> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArray> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<BoolT> Method_JSArray_IsEmpty_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = IsNumberEqual_0(state_, TNode<Number>{tmp2}, TNode<Number>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<JSArray> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<BoolT>{tmp6};
}

}  // namespace internal
}  // namespace v8

