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

const char* kBuiltinNameSlice_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return "%TypedArray%.prototype.slice";
}

void FastCopy_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_count, compiler::CodeAssemblerLabel* label_IfSlow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, RawPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, RawPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, RawPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT, Int32T, UintPtrT, Int32T, UintPtrT, UintPtrT, RawPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_src, p_dest, p_k, p_count);

  if (block0.is_used()) {
    TNode<JSTypedArray> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp4, &block3, &block4, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<JSTypedArray> tmp5;
    TNode<JSTypedArray> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<JSTypedArray> tmp9;
    TNode<JSTypedArray> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<Int32T> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp9});
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    TNode<Int32T> tmp15;
    USE(tmp15);
    std::tie(tmp14, tmp15) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{tmp10}).Flatten();
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = ElementsKindNotEqual_0(state_, TNode<Int32T>{tmp13}, TNode<Int32T>{tmp15});
    ca_.Branch(tmp16, &block5, &block6, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block5.is_used()) {
    TNode<JSTypedArray> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<Int32T> tmp21;
    TNode<UintPtrT> tmp22;
    TNode<Int32T> tmp23;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block1);
  }

  if (block6.is_used()) {
    TNode<JSTypedArray> tmp24;
    TNode<JSTypedArray> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<UintPtrT> tmp27;
    TNode<Int32T> tmp28;
    TNode<UintPtrT> tmp29;
    TNode<Int32T> tmp30;
    ca_.Bind(&block6, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp31);
    TNode<JSArrayBuffer>tmp32 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp25, tmp31});
    TNode<IntPtrT> tmp33 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp33);
    TNode<JSArrayBuffer>tmp34 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp24, tmp33});
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp32}, TNode<HeapObject>{tmp34});
    ca_.Branch(tmp35, &block7, &block8, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30);
  }

  if (block7.is_used()) {
    TNode<JSTypedArray> tmp36;
    TNode<JSTypedArray> tmp37;
    TNode<UintPtrT> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<Int32T> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Int32T> tmp42;
    ca_.Bind(&block7, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<JSTypedArray> tmp43;
    TNode<JSTypedArray> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<UintPtrT> tmp46;
    TNode<Int32T> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Int32T> tmp49;
    ca_.Bind(&block8, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<UintPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp46}, TNode<UintPtrT>{tmp50});
    ca_.Branch(tmp51, &block12, &block13, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp48, tmp49, tmp46, tmp46);
  }

  if (block12.is_used()) {
    TNode<JSTypedArray> tmp52;
    TNode<JSTypedArray> tmp53;
    TNode<UintPtrT> tmp54;
    TNode<UintPtrT> tmp55;
    TNode<Int32T> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<Int32T> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<Int32T> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<UintPtrT> tmp62;
    ca_.Bind(&block12, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    ca_.Goto(&block10, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58);
  }

  if (block13.is_used()) {
    TNode<JSTypedArray> tmp63;
    TNode<JSTypedArray> tmp64;
    TNode<UintPtrT> tmp65;
    TNode<UintPtrT> tmp66;
    TNode<Int32T> tmp67;
    TNode<UintPtrT> tmp68;
    TNode<Int32T> tmp69;
    TNode<UintPtrT> tmp70;
    TNode<Int32T> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<UintPtrT> tmp73;
    ca_.Bind(&block13, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    TNode<UintPtrT> tmp74;
    USE(tmp74);
    tmp74 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    TNode<UintPtrT> tmp75;
    USE(tmp75);
    tmp75 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp74}, TNode<UintPtrT>{tmp70});
    TNode<BoolT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp73}, TNode<UintPtrT>{tmp75});
    ca_.Branch(tmp76, &block14, &block15, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp75);
  }

  if (block14.is_used()) {
    TNode<JSTypedArray> tmp77;
    TNode<JSTypedArray> tmp78;
    TNode<UintPtrT> tmp79;
    TNode<UintPtrT> tmp80;
    TNode<Int32T> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<Int32T> tmp83;
    TNode<UintPtrT> tmp84;
    TNode<Int32T> tmp85;
    TNode<UintPtrT> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<UintPtrT> tmp88;
    ca_.Bind(&block14, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
    ca_.Goto(&block10, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83);
  }

  if (block15.is_used()) {
    TNode<JSTypedArray> tmp89;
    TNode<JSTypedArray> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<Int32T> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<Int32T> tmp95;
    TNode<UintPtrT> tmp96;
    TNode<Int32T> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    ca_.Bind(&block15, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<UintPtrT> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp99}, TNode<UintPtrT>{tmp96});
    TNode<UintPtrT> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp91}, TNode<UintPtrT>{tmp102});
    ca_.Branch(tmp103, &block19, &block20, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp101, tmp94, tmp95, tmp91, tmp91);
  }

  if (block10.is_used()) {
    TNode<JSTypedArray> tmp104;
    TNode<JSTypedArray> tmp105;
    TNode<UintPtrT> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<Int32T> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<Int32T> tmp110;
    ca_.Bind(&block10, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<JSTypedArray> tmp111;
    TNode<JSTypedArray> tmp112;
    TNode<UintPtrT> tmp113;
    TNode<UintPtrT> tmp114;
    TNode<Int32T> tmp115;
    TNode<UintPtrT> tmp116;
    TNode<Int32T> tmp117;
    TNode<UintPtrT> tmp118;
    TNode<UintPtrT> tmp119;
    TNode<Int32T> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<UintPtrT> tmp122;
    ca_.Bind(&block19, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    ca_.Goto(&block17, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118);
  }

  if (block20.is_used()) {
    TNode<JSTypedArray> tmp123;
    TNode<JSTypedArray> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<Int32T> tmp127;
    TNode<UintPtrT> tmp128;
    TNode<Int32T> tmp129;
    TNode<UintPtrT> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<Int32T> tmp132;
    TNode<UintPtrT> tmp133;
    TNode<UintPtrT> tmp134;
    ca_.Bind(&block20, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
    TNode<UintPtrT> tmp135;
    USE(tmp135);
    tmp135 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    TNode<UintPtrT> tmp136;
    USE(tmp136);
    tmp136 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp135}, TNode<UintPtrT>{tmp131});
    TNode<BoolT> tmp137;
    USE(tmp137);
    tmp137 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp134}, TNode<UintPtrT>{tmp136});
    ca_.Branch(tmp137, &block21, &block22, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp136);
  }

  if (block21.is_used()) {
    TNode<JSTypedArray> tmp138;
    TNode<JSTypedArray> tmp139;
    TNode<UintPtrT> tmp140;
    TNode<UintPtrT> tmp141;
    TNode<Int32T> tmp142;
    TNode<UintPtrT> tmp143;
    TNode<Int32T> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<UintPtrT> tmp146;
    TNode<Int32T> tmp147;
    TNode<UintPtrT> tmp148;
    TNode<UintPtrT> tmp149;
    TNode<UintPtrT> tmp150;
    ca_.Bind(&block21, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150);
    ca_.Goto(&block17, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145);
  }

  if (block22.is_used()) {
    TNode<JSTypedArray> tmp151;
    TNode<JSTypedArray> tmp152;
    TNode<UintPtrT> tmp153;
    TNode<UintPtrT> tmp154;
    TNode<Int32T> tmp155;
    TNode<UintPtrT> tmp156;
    TNode<Int32T> tmp157;
    TNode<UintPtrT> tmp158;
    TNode<UintPtrT> tmp159;
    TNode<Int32T> tmp160;
    TNode<UintPtrT> tmp161;
    TNode<UintPtrT> tmp162;
    TNode<UintPtrT> tmp163;
    ca_.Bind(&block22, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    TNode<UintPtrT> tmp164;
    USE(tmp164);
    tmp164 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp162}, TNode<UintPtrT>{tmp159});
    TNode<RawPtrT> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp151});
    TNode<IntPtrT> tmp166;
    USE(tmp166);
    tmp166 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT>{tmp164});
    TNode<RawPtrT> tmp167;
    USE(tmp167);
    tmp167 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{tmp165}, TNode<IntPtrT>{tmp166});
    TNode<RawPtrT> tmp168;
    USE(tmp168);
    tmp168 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp152});
    TypedArrayBuiltinsAssembler(state_).CallCMemmove(TNode<RawPtrT>{tmp168}, TNode<RawPtrT>{tmp167}, TNode<UintPtrT>{tmp158});
    ca_.Goto(&block31, tmp151, tmp152, tmp153, tmp154);
  }

  if (block17.is_used()) {
    TNode<JSTypedArray> tmp169;
    TNode<JSTypedArray> tmp170;
    TNode<UintPtrT> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<Int32T> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<Int32T> tmp175;
    TNode<UintPtrT> tmp176;
    ca_.Bind(&block17, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block26.is_used()) {
    TNode<JSTypedArray> tmp177;
    TNode<JSTypedArray> tmp178;
    TNode<UintPtrT> tmp179;
    TNode<UintPtrT> tmp180;
    TNode<Int32T> tmp181;
    TNode<UintPtrT> tmp182;
    TNode<Int32T> tmp183;
    TNode<UintPtrT> tmp184;
    TNode<UintPtrT> tmp185;
    TNode<RawPtrT> tmp186;
    ca_.Bind(&block26, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186);
    CodeStubAssembler(state_).FailAssert("Torque assert 'countBytes <= dest.byte_length' failed", "src/builtins/typed-array-slice.tq", 36);
  }

  if (block25.is_used()) {
    TNode<JSTypedArray> tmp187;
    TNode<JSTypedArray> tmp188;
    TNode<UintPtrT> tmp189;
    TNode<UintPtrT> tmp190;
    TNode<Int32T> tmp191;
    TNode<UintPtrT> tmp192;
    TNode<Int32T> tmp193;
    TNode<UintPtrT> tmp194;
    TNode<UintPtrT> tmp195;
    TNode<RawPtrT> tmp196;
    ca_.Bind(&block25, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196);
  }

  if (block30.is_used()) {
    TNode<JSTypedArray> tmp197;
    TNode<JSTypedArray> tmp198;
    TNode<UintPtrT> tmp199;
    TNode<UintPtrT> tmp200;
    TNode<Int32T> tmp201;
    TNode<UintPtrT> tmp202;
    TNode<Int32T> tmp203;
    TNode<UintPtrT> tmp204;
    TNode<UintPtrT> tmp205;
    TNode<RawPtrT> tmp206;
    ca_.Bind(&block30, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206);
    CodeStubAssembler(state_).FailAssert("Torque assert 'countBytes <= src.byte_length - startOffset' failed", "src/builtins/typed-array-slice.tq", 37);
  }

  if (block29.is_used()) {
    TNode<JSTypedArray> tmp207;
    TNode<JSTypedArray> tmp208;
    TNode<UintPtrT> tmp209;
    TNode<UintPtrT> tmp210;
    TNode<Int32T> tmp211;
    TNode<UintPtrT> tmp212;
    TNode<Int32T> tmp213;
    TNode<UintPtrT> tmp214;
    TNode<UintPtrT> tmp215;
    TNode<RawPtrT> tmp216;
    ca_.Bind(&block29, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfSlow);
  }

    TNode<JSTypedArray> tmp217;
    TNode<JSTypedArray> tmp218;
    TNode<UintPtrT> tmp219;
    TNode<UintPtrT> tmp220;
    ca_.Bind(&block31, &tmp217, &tmp218, &tmp219, &tmp220);
}

void SlowCopy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_final) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_src, p_dest, p_k, p_final);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<JSTypedArray> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp1});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp5});
    TNode<Int32T> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp2});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT>{tmp6}, TNode<BoolT>{tmp8});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<JSTypedArray> tmp11;
    TNode<JSTypedArray> tmp12;
    TNode<UintPtrT> tmp13;
    TNode<UintPtrT> tmp14;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp10}, MessageTemplate::kBigIntMixedTypes);
  }

  if (block3.is_used()) {
    TNode<Context> tmp15;
    TNode<JSTypedArray> tmp16;
    TNode<JSTypedArray> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TypedArrayBuiltinsAssembler(state_).CallCCopyTypedArrayElementsSlice(TNode<JSTypedArray>{tmp16}, TNode<JSTypedArray>{tmp17}, TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    ca_.Goto(&block4, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

    TNode<Context> tmp20;
    TNode<JSTypedArray> tmp21;
    TNode<JSTypedArray> tmp22;
    TNode<UintPtrT> tmp23;
    TNode<UintPtrT> tmp24;
    ca_.Bind(&block4, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
}

TF_BUILTIN(TypedArrayPrototypeSlice, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray, JSTypedArray> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray, JSTypedArray, JSTypedArray> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray, JSTypedArray, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray, JSTypedArray, JSTypedArray, JSTypedArray, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, JSTypedArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSTypedArray> tmp5;
    USE(tmp5);
    tmp5 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArray(TNode<Context>{tmp3}, TNode<Object>{tmp4}, kBuiltinNameSlice_0(state_));
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp6);
    TNode<UintPtrT>tmp7 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp5, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp8});
    TNode<Oddball> tmp10;
    USE(tmp10);
    tmp10 = Undefined_0(state_);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp11, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp7, tmp9);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<NativeContext> tmp15;
    TNode<Object> tmp16;
    TNode<JSTypedArray> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<Object> tmp19;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = ConvertToRelativeIndex_1(state_, TNode<Context>{tmp15}, TNode<Object>{tmp19}, TNode<UintPtrT>{tmp18});
    ca_.Goto(&block3, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<NativeContext> tmp24;
    TNode<Object> tmp25;
    TNode<JSTypedArray> tmp26;
    TNode<UintPtrT> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block2, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block3, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp30;
    TNode<RawPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<NativeContext> tmp33;
    TNode<Object> tmp34;
    TNode<JSTypedArray> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<Object> tmp37;
    TNode<UintPtrT> tmp38;
    ca_.Bind(&block3, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp30}, TNode<RawPtrT>{tmp31}, TNode<IntPtrT>{tmp32}}, TNode<IntPtrT>{tmp39});
    TNode<Oddball> tmp41;
    USE(tmp41);
    tmp41 = Undefined_0(state_);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp40}, TNode<HeapObject>{tmp41});
    ca_.Branch(tmp42, &block5, &block6, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp40);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<JSTypedArray> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<Object> tmp50;
    TNode<UintPtrT> tmp51;
    TNode<Object> tmp52;
    ca_.Bind(&block5, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<UintPtrT> tmp53;
    USE(tmp53);
    tmp53 = ConvertToRelativeIndex_1(state_, TNode<Context>{tmp46}, TNode<Object>{tmp52}, TNode<UintPtrT>{tmp49});
    ca_.Goto(&block7, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp54;
    TNode<RawPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<JSTypedArray> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<Object> tmp61;
    TNode<UintPtrT> tmp62;
    TNode<Object> tmp63;
    ca_.Bind(&block6, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block7, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp60);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp64;
    TNode<RawPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<NativeContext> tmp67;
    TNode<Object> tmp68;
    TNode<JSTypedArray> tmp69;
    TNode<UintPtrT> tmp70;
    TNode<Object> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<Object> tmp73;
    TNode<UintPtrT> tmp74;
    ca_.Bind(&block7, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<UintPtrT> tmp75;
    USE(tmp75);
    tmp75 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp74}, TNode<UintPtrT>{tmp72});
    TNode<IntPtrT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp75});
    TNode<IntPtrT> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).IntPtrMax(TNode<IntPtrT>{tmp76}, TNode<IntPtrT>{tmp77});
    TNode<UintPtrT> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp78});
    TNode<JSTypedArray> tmp80;
    USE(tmp80);
    tmp80 = TypedArraySpeciesCreateByLength_0(state_, TNode<Context>{tmp67}, kBuiltinNameSlice_0(state_), TNode<JSTypedArray>{tmp69}, TNode<UintPtrT>{tmp79});
    TNode<UintPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp79}, TNode<UintPtrT>{tmp81});
    ca_.Branch(tmp82, &block9, &block10, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp79, tmp80);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp83;
    TNode<RawPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<NativeContext> tmp86;
    TNode<Object> tmp87;
    TNode<JSTypedArray> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<Object> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<Object> tmp92;
    TNode<UintPtrT> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<JSTypedArray> tmp95;
    ca_.Bind(&block9, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<JSTypedArray> tmp96;
    USE(tmp96);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp96 = EnsureAttached_0(state_, TNode<JSTypedArray>{tmp88}, &label0);
    ca_.Goto(&block15, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp88, tmp96);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp88);
    }
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp97;
    TNode<RawPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<NativeContext> tmp100;
    TNode<Object> tmp101;
    TNode<JSTypedArray> tmp102;
    TNode<UintPtrT> tmp103;
    TNode<Object> tmp104;
    TNode<UintPtrT> tmp105;
    TNode<Object> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<UintPtrT> tmp108;
    TNode<JSTypedArray> tmp109;
    TNode<JSTypedArray> tmp110;
    ca_.Bind(&block16, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp100}, MessageTemplate::kDetachedOperation, kBuiltinNameSlice_0(state_));
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp111;
    TNode<RawPtrT> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<NativeContext> tmp114;
    TNode<Object> tmp115;
    TNode<JSTypedArray> tmp116;
    TNode<UintPtrT> tmp117;
    TNode<Object> tmp118;
    TNode<UintPtrT> tmp119;
    TNode<Object> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<UintPtrT> tmp122;
    TNode<JSTypedArray> tmp123;
    TNode<JSTypedArray> tmp124;
    TNode<JSTypedArray> tmp125;
    ca_.Bind(&block15, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    compiler::CodeAssemblerLabel label0(&ca_);
    FastCopy_0(state_, TNode<JSTypedArray>{tmp125}, TNode<JSTypedArray>{tmp123}, TNode<UintPtrT>{tmp119}, TNode<UintPtrT>{tmp122}, &label0);
    ca_.Goto(&block17, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp125, tmp125, tmp123, tmp119, tmp122);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp125, tmp125, tmp123, tmp119, tmp122);
    }
  }

  if (block18.is_used()) {
    TNode<RawPtrT> tmp126;
    TNode<RawPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<NativeContext> tmp129;
    TNode<Object> tmp130;
    TNode<JSTypedArray> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<Object> tmp133;
    TNode<UintPtrT> tmp134;
    TNode<Object> tmp135;
    TNode<UintPtrT> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<JSTypedArray> tmp138;
    TNode<JSTypedArray> tmp139;
    TNode<JSTypedArray> tmp140;
    TNode<JSTypedArray> tmp141;
    TNode<UintPtrT> tmp142;
    TNode<UintPtrT> tmp143;
    ca_.Bind(&block18, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
    SlowCopy_0(state_, TNode<Context>{tmp129}, TNode<JSTypedArray>{tmp131}, TNode<JSTypedArray>{tmp138}, TNode<UintPtrT>{tmp134}, TNode<UintPtrT>{tmp136});
    ca_.Goto(&block11, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp144;
    TNode<RawPtrT> tmp145;
    TNode<IntPtrT> tmp146;
    TNode<NativeContext> tmp147;
    TNode<Object> tmp148;
    TNode<JSTypedArray> tmp149;
    TNode<UintPtrT> tmp150;
    TNode<Object> tmp151;
    TNode<UintPtrT> tmp152;
    TNode<Object> tmp153;
    TNode<UintPtrT> tmp154;
    TNode<UintPtrT> tmp155;
    TNode<JSTypedArray> tmp156;
    TNode<JSTypedArray> tmp157;
    TNode<JSTypedArray> tmp158;
    TNode<JSTypedArray> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<UintPtrT> tmp161;
    ca_.Bind(&block17, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    ca_.Goto(&block11, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp162;
    TNode<RawPtrT> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<NativeContext> tmp165;
    TNode<Object> tmp166;
    TNode<JSTypedArray> tmp167;
    TNode<UintPtrT> tmp168;
    TNode<Object> tmp169;
    TNode<UintPtrT> tmp170;
    TNode<Object> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<JSTypedArray> tmp174;
    ca_.Bind(&block11, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    ca_.Goto(&block10, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp175;
    TNode<RawPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<NativeContext> tmp178;
    TNode<Object> tmp179;
    TNode<JSTypedArray> tmp180;
    TNode<UintPtrT> tmp181;
    TNode<Object> tmp182;
    TNode<UintPtrT> tmp183;
    TNode<Object> tmp184;
    TNode<UintPtrT> tmp185;
    TNode<UintPtrT> tmp186;
    TNode<JSTypedArray> tmp187;
    ca_.Bind(&block10, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187);
    arguments.PopAndReturn(tmp187);
  }
}

}  // namespace internal
}  // namespace v8

