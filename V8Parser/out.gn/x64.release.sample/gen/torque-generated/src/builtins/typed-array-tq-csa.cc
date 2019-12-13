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

TNode<Smi> kStoreSucceded_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
return TNode<Smi>{tmp0};
}

TNode<Smi> kStoreFailureArrayDetached_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
return TNode<Smi>{tmp0};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_elementsKind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, BuiltinPtr, BuiltinPtr, BuiltinPtr> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, BuiltinPtr, BuiltinPtr, BuiltinPtr> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elementsKind);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsElementsKindGreaterThan(TNode<Int32T>{tmp0}, UINT32_ELEMENTS);
    ca_.Branch(tmp1, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Int32T> tmp2;
    ca_.Bind(&block2, &tmp2);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, INT32_ELEMENTS);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp2}, TNode<Int32T>{tmp3});
    ca_.Branch(tmp4, &block5, &block6, tmp2);
  }

  if (block5.is_used()) {
    TNode<Int32T> tmp5;
    ca_.Bind(&block5, &tmp5);
    TNode<BuiltinPtr> tmp6;
    USE(tmp6);
    TNode<BuiltinPtr> tmp7;
    USE(tmp7);
    TNode<BuiltinPtr> tmp8;
    USE(tmp8);
    std::tie(tmp6, tmp7, tmp8) = GetTypedArrayAccessor_Int32Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp5, tmp6, tmp7, tmp8);
  }

  if (block6.is_used()) {
    TNode<Int32T> tmp9;
    ca_.Bind(&block6, &tmp9);
    TNode<Int32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, FLOAT32_ELEMENTS);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block8, &block9, tmp9);
  }

  if (block8.is_used()) {
    TNode<Int32T> tmp12;
    ca_.Bind(&block8, &tmp12);
    TNode<BuiltinPtr> tmp13;
    USE(tmp13);
    TNode<BuiltinPtr> tmp14;
    USE(tmp14);
    TNode<BuiltinPtr> tmp15;
    USE(tmp15);
    std::tie(tmp13, tmp14, tmp15) = GetTypedArrayAccessor_Float32Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp12, tmp13, tmp14, tmp15);
  }

  if (block9.is_used()) {
    TNode<Int32T> tmp16;
    ca_.Bind(&block9, &tmp16);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, FLOAT64_ELEMENTS);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block11, &block12, tmp16);
  }

  if (block11.is_used()) {
    TNode<Int32T> tmp19;
    ca_.Bind(&block11, &tmp19);
    TNode<BuiltinPtr> tmp20;
    USE(tmp20);
    TNode<BuiltinPtr> tmp21;
    USE(tmp21);
    TNode<BuiltinPtr> tmp22;
    USE(tmp22);
    std::tie(tmp20, tmp21, tmp22) = GetTypedArrayAccessor_Float64Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp19, tmp20, tmp21, tmp22);
  }

  if (block12.is_used()) {
    TNode<Int32T> tmp23;
    ca_.Bind(&block12, &tmp23);
    TNode<Int32T> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, UINT8_CLAMPED_ELEMENTS);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp23}, TNode<Int32T>{tmp24});
    ca_.Branch(tmp25, &block14, &block15, tmp23);
  }

  if (block14.is_used()) {
    TNode<Int32T> tmp26;
    ca_.Bind(&block14, &tmp26);
    TNode<BuiltinPtr> tmp27;
    USE(tmp27);
    TNode<BuiltinPtr> tmp28;
    USE(tmp28);
    TNode<BuiltinPtr> tmp29;
    USE(tmp29);
    std::tie(tmp27, tmp28, tmp29) = GetTypedArrayAccessor_Uint8ClampedElements_0(state_).Flatten();
    ca_.Goto(&block1, tmp26, tmp27, tmp28, tmp29);
  }

  if (block15.is_used()) {
    TNode<Int32T> tmp30;
    ca_.Bind(&block15, &tmp30);
    TNode<Int32T> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, BIGUINT64_ELEMENTS);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp30}, TNode<Int32T>{tmp31});
    ca_.Branch(tmp32, &block17, &block18, tmp30);
  }

  if (block17.is_used()) {
    TNode<Int32T> tmp33;
    ca_.Bind(&block17, &tmp33);
    TNode<BuiltinPtr> tmp34;
    USE(tmp34);
    TNode<BuiltinPtr> tmp35;
    USE(tmp35);
    TNode<BuiltinPtr> tmp36;
    USE(tmp36);
    std::tie(tmp34, tmp35, tmp36) = GetTypedArrayAccessor_BigUint64Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp33, tmp34, tmp35, tmp36);
  }

  if (block18.is_used()) {
    TNode<Int32T> tmp37;
    ca_.Bind(&block18, &tmp37);
    TNode<Int32T> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, BIGINT64_ELEMENTS);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp37}, TNode<Int32T>{tmp38});
    ca_.Branch(tmp39, &block20, &block21, tmp37);
  }

  if (block20.is_used()) {
    TNode<Int32T> tmp40;
    ca_.Bind(&block20, &tmp40);
    TNode<BuiltinPtr> tmp41;
    USE(tmp41);
    TNode<BuiltinPtr> tmp42;
    USE(tmp42);
    TNode<BuiltinPtr> tmp43;
    USE(tmp43);
    std::tie(tmp41, tmp42, tmp43) = GetTypedArrayAccessor_BigInt64Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp40, tmp41, tmp42, tmp43);
  }

  if (block21.is_used()) {
    TNode<Int32T> tmp44;
    ca_.Bind(&block21, &tmp44);
    ca_.Goto(&block4, tmp44);
  }

  if (block3.is_used()) {
    TNode<Int32T> tmp45;
    ca_.Bind(&block3, &tmp45);
    TNode<Int32T> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, UINT8_ELEMENTS);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp45}, TNode<Int32T>{tmp46});
    ca_.Branch(tmp47, &block22, &block23, tmp45);
  }

  if (block22.is_used()) {
    TNode<Int32T> tmp48;
    ca_.Bind(&block22, &tmp48);
    TNode<BuiltinPtr> tmp49;
    USE(tmp49);
    TNode<BuiltinPtr> tmp50;
    USE(tmp50);
    TNode<BuiltinPtr> tmp51;
    USE(tmp51);
    std::tie(tmp49, tmp50, tmp51) = GetTypedArrayAccessor_Uint8Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp48, tmp49, tmp50, tmp51);
  }

  if (block23.is_used()) {
    TNode<Int32T> tmp52;
    ca_.Bind(&block23, &tmp52);
    TNode<Int32T> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, INT8_ELEMENTS);
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp52}, TNode<Int32T>{tmp53});
    ca_.Branch(tmp54, &block25, &block26, tmp52);
  }

  if (block25.is_used()) {
    TNode<Int32T> tmp55;
    ca_.Bind(&block25, &tmp55);
    TNode<BuiltinPtr> tmp56;
    USE(tmp56);
    TNode<BuiltinPtr> tmp57;
    USE(tmp57);
    TNode<BuiltinPtr> tmp58;
    USE(tmp58);
    std::tie(tmp56, tmp57, tmp58) = GetTypedArrayAccessor_Int8Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp55, tmp56, tmp57, tmp58);
  }

  if (block26.is_used()) {
    TNode<Int32T> tmp59;
    ca_.Bind(&block26, &tmp59);
    TNode<Int32T> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, UINT16_ELEMENTS);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp59}, TNode<Int32T>{tmp60});
    ca_.Branch(tmp61, &block28, &block29, tmp59);
  }

  if (block28.is_used()) {
    TNode<Int32T> tmp62;
    ca_.Bind(&block28, &tmp62);
    TNode<BuiltinPtr> tmp63;
    USE(tmp63);
    TNode<BuiltinPtr> tmp64;
    USE(tmp64);
    TNode<BuiltinPtr> tmp65;
    USE(tmp65);
    std::tie(tmp63, tmp64, tmp65) = GetTypedArrayAccessor_Uint16Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp62, tmp63, tmp64, tmp65);
  }

  if (block29.is_used()) {
    TNode<Int32T> tmp66;
    ca_.Bind(&block29, &tmp66);
    TNode<Int32T> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, INT16_ELEMENTS);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp66}, TNode<Int32T>{tmp67});
    ca_.Branch(tmp68, &block31, &block32, tmp66);
  }

  if (block31.is_used()) {
    TNode<Int32T> tmp69;
    ca_.Bind(&block31, &tmp69);
    TNode<BuiltinPtr> tmp70;
    USE(tmp70);
    TNode<BuiltinPtr> tmp71;
    USE(tmp71);
    TNode<BuiltinPtr> tmp72;
    USE(tmp72);
    std::tie(tmp70, tmp71, tmp72) = GetTypedArrayAccessor_Int16Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp69, tmp70, tmp71, tmp72);
  }

  if (block32.is_used()) {
    TNode<Int32T> tmp73;
    ca_.Bind(&block32, &tmp73);
    TNode<Int32T> tmp74;
    USE(tmp74);
    tmp74 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, UINT32_ELEMENTS);
    TNode<BoolT> tmp75;
    USE(tmp75);
    tmp75 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp73}, TNode<Int32T>{tmp74});
    ca_.Branch(tmp75, &block34, &block35, tmp73);
  }

  if (block34.is_used()) {
    TNode<Int32T> tmp76;
    ca_.Bind(&block34, &tmp76);
    TNode<BuiltinPtr> tmp77;
    USE(tmp77);
    TNode<BuiltinPtr> tmp78;
    USE(tmp78);
    TNode<BuiltinPtr> tmp79;
    USE(tmp79);
    std::tie(tmp77, tmp78, tmp79) = GetTypedArrayAccessor_Uint32Elements_0(state_).Flatten();
    ca_.Goto(&block1, tmp76, tmp77, tmp78, tmp79);
  }

  if (block35.is_used()) {
    TNode<Int32T> tmp80;
    ca_.Bind(&block35, &tmp80);
    ca_.Goto(&block4, tmp80);
  }

  if (block4.is_used()) {
    TNode<Int32T> tmp81;
    ca_.Bind(&block4, &tmp81);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<Int32T> tmp82;
    TNode<BuiltinPtr> tmp83;
    TNode<BuiltinPtr> tmp84;
    TNode<BuiltinPtr> tmp85;
    ca_.Bind(&block1, &tmp82, &tmp83, &tmp84, &tmp85);
    ca_.Goto(&block36, tmp82, tmp83, tmp84, tmp85);
  }

    TNode<Int32T> tmp86;
    TNode<BuiltinPtr> tmp87;
    TNode<BuiltinPtr> tmp88;
    TNode<BuiltinPtr> tmp89;
    ca_.Bind(&block36, &tmp86, &tmp87, &tmp88, &tmp89);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp87}, TNode<BuiltinPtr>{tmp88}, TNode<BuiltinPtr>{tmp89}};
}

TNode<JSTypedArray> EnsureAttached_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array, compiler::CodeAssemblerLabel* label_Detached) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSTypedArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp1);
    TNode<JSArrayBuffer>tmp2 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp2});
    ca_.Branch(tmp3, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<JSTypedArray> tmp4;
    ca_.Bind(&block3, &tmp4);
    ca_.Goto(label_Detached);
  }

  if (block4.is_used()) {
    TNode<JSTypedArray> tmp5;
    ca_.Bind(&block4, &tmp5);
    TNode<JSTypedArray> tmp6;
    USE(tmp6);
    tmp6 = (TNode<JSTypedArray>{tmp5});
    ca_.Goto(&block5, tmp5, tmp6);
  }

    TNode<JSTypedArray> tmp7;
    TNode<JSTypedArray> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSTypedArray>{tmp8};
}

TorqueStructAttachedJSTypedArrayWitness_0 NewAttachedJSTypedArrayWitness_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSTypedArray, JSTypedArray, JSTypedArray, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSTypedArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp0});
    TNode<BuiltinPtr> tmp2;
    USE(tmp2);
    TNode<BuiltinPtr> tmp3;
    USE(tmp3);
    TNode<BuiltinPtr> tmp4;
    USE(tmp4);
    std::tie(tmp2, tmp3, tmp4) = GetTypedArrayAccessor_0(state_, TNode<Int32T>{tmp1}).Flatten();
    ca_.Goto(&block2, tmp0, tmp0, tmp0, tmp2);
  }

    TNode<JSTypedArray> tmp5;
    TNode<JSTypedArray> tmp6;
    TNode<JSTypedArray> tmp7;
    TNode<BuiltinPtr> tmp8;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8);
  return TorqueStructAttachedJSTypedArrayWitness_0{TNode<JSTypedArray>{tmp6}, TNode<JSTypedArray>{tmp7}, TNode<BuiltinPtr>{tmp8}};
}

ElementsKind KindForArrayType_Uint8Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return UINT8_ELEMENTS;
}

ElementsKind KindForArrayType_Int8Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return INT8_ELEMENTS;
}

ElementsKind KindForArrayType_Uint16Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return UINT16_ELEMENTS;
}

ElementsKind KindForArrayType_Int16Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return INT16_ELEMENTS;
}

ElementsKind KindForArrayType_Uint32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return UINT32_ELEMENTS;
}

ElementsKind KindForArrayType_Int32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return INT32_ELEMENTS;
}

ElementsKind KindForArrayType_Float32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return FLOAT32_ELEMENTS;
}

ElementsKind KindForArrayType_Float64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return FLOAT64_ELEMENTS;
}

ElementsKind KindForArrayType_Uint8ClampedElements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return UINT8_CLAMPED_ELEMENTS;
}

ElementsKind KindForArrayType_BigUint64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return BIGUINT64_ELEMENTS;
}

ElementsKind KindForArrayType_BigInt64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return BIGINT64_ELEMENTS;
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Int32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Int32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Int32Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Float32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Float32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Float32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Float32Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Float64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Float64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Float64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Float64Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint8ClampedElements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Uint8ClampedElements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Uint8ClampedElements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Uint8ClampedElements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_BigUint64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_BigUint64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_BigUint64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_BigUint64Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_BigInt64Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_BigInt64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_BigInt64Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_BigInt64Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint8Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Uint8Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Uint8Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Uint8Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int8Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Int8Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Int8Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Int8Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint16Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Uint16Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Uint16Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Uint16Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int16Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Int16Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Int16Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Int16Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint32Elements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kLoadTypedElement_Uint32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementNumeric_Uint32Elements_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kStoreTypedElementJSAny_Uint32Elements_0)));
  }

    TNode<BuiltinPtr> tmp0;
    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp0, &tmp1, &tmp2);
  return TorqueStructTypedArrayAccessor_0{TNode<BuiltinPtr>{tmp0}, TNode<BuiltinPtr>{tmp1}, TNode<BuiltinPtr>{tmp2}};
}

TF_BUILTIN(LoadTypedElement_Int32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Int32Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Int32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Int32Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Int32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Int32Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Float32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Float32Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Float32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Float32Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Float32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Float32Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Float64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Float64Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Float64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Float64Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Float64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Float64Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Uint8ClampedElements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Uint8ClampedElements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Uint8ClampedElements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Uint8ClampedElements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Uint8ClampedElements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Uint8ClampedElements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_BigUint64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_BigUint64Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_BigUint64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_BigUint64Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_BigUint64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_BigUint64Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_BigInt64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_BigInt64Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_BigInt64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_BigInt64Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_BigInt64Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_BigInt64Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Uint8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Uint8Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Uint8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Uint8Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Uint8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Uint8Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Int8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Int8Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Int8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Int8Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Int8Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Int8Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Uint16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Uint16Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Uint16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Uint16Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Uint16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Uint16Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Int16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Int16Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Int16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Int16Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Int16Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Int16Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(LoadTypedElement_Uint32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<RawPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp1});
    TNode<Numeric> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadFixedTypedArrayElementAsTagged(TNode<RawPtrT>{tmp3}, TNode<UintPtrT>{tmp2}, (KindForArrayType_Uint32Elements_0(state_)));
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementNumeric_Uint32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Numeric> parameter3 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Numeric> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromNumeric(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Numeric>{tmp3}, (KindForArrayType_Uint32Elements_0(state_)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(StoreTypedElementJSAny_Uint32Elements_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSTypedArray> parameter1 = UncheckedCast<JSTypedArray>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<UintPtrT> parameter2 = UncheckedCast<UintPtrT>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    TypedArrayBuiltinsAssembler(state_).StoreJSTypedArrayElementFromTagged(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp2}, TNode<Object>{tmp3}, (KindForArrayType_Uint32Elements_0(state_)), &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp0, tmp1, tmp2, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = kStoreFailureArrayDetached_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = kStoreSucceded_0(state_);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

}  // namespace internal
}  // namespace v8

