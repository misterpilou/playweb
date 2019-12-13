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

TNode<BigInt> Convert_BigInt_MutableBigInt_0(compiler::CodeAssemblerState* state_, TNode<BigInt> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BigInt> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<BigInt> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BigInt> tmp1;
    USE(tmp1);
    tmp1 = Convert_BigIntBase_MutableBigInt_0(state_, TNode<BigInt>{tmp0});
    TNode<BigInt> tmp2;
    USE(tmp2);
    tmp2 = (TNode<BigInt>{tmp1});
    ca_.Goto(&block6, tmp0, tmp2);
  }

  if (block5.is_used()) {
    TNode<BigInt> tmp3;
    ca_.Bind(&block5, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'bigint::IsCanonicalized(i)' failed", "src/builtins/bigint.tq", 20);
  }

  if (block4.is_used()) {
    TNode<BigInt> tmp4;
    ca_.Bind(&block4, &tmp4);
  }

    TNode<BigInt> tmp5;
    TNode<BigInt> tmp6;
    ca_.Bind(&block6, &tmp5, &tmp6);
  return TNode<BigInt>{tmp6};
}

TNode<Uint32T> kPositiveSign_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Uint32T> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
return TNode<Uint32T>{tmp0};
}

TNode<Uint32T> kNegativeSign_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Uint32T> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_uint32_constexpr_int31_0(state_, 1);
return TNode<Uint32T>{tmp0};
}

TNode<BoolT> IsCanonicalized_0(compiler::CodeAssemblerState* state_, TNode<BigInt> p_bigint) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_bigint);

  if (block0.is_used()) {
    TNode<BigInt> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<BigInt> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp4});
    TNode<Uint32T> tmp7;
    USE(tmp7);
    tmp7 = kPositiveSign_0(state_);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp6}, TNode<Uint32T>{tmp7});
    ca_.Goto(&block1, tmp4, tmp8);
  }

  if (block3.is_used()) {
    TNode<BigInt> tmp9;
    TNode<IntPtrT> tmp10;
    ca_.Bind(&block3, &tmp9, &tmp10);
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11});
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp9}, TNode<IntPtrT>{tmp12});
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp14});
    ca_.Goto(&block1, tmp9, tmp15);
  }

  if (block1.is_used()) {
    TNode<BigInt> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block1, &tmp16, &tmp17);
    ca_.Goto(&block4, tmp16, tmp17);
  }

    TNode<BigInt> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block4, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<Uint32T> InvertSign_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_sign) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_sign);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = kPositiveSign_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp0}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Uint32T> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<Uint32T> tmp4;
    USE(tmp4);
    tmp4 = kNegativeSign_0(state_);
    ca_.Goto(&block4, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Uint32T> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = kPositiveSign_0(state_);
    ca_.Goto(&block4, tmp5, tmp6);
  }

  if (block4.is_used()) {
    TNode<Uint32T> tmp7;
    TNode<Uint32T> tmp8;
    ca_.Bind(&block4, &tmp7, &tmp8);
    ca_.Goto(&block6, tmp7, tmp8);
  }

    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    ca_.Bind(&block6, &tmp9, &tmp10);
  return TNode<Uint32T>{tmp10};
}

TNode<BigInt> AllocateEmptyBigIntNoThrow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_sign, TNode<IntPtrT> p_length, compiler::CodeAssemblerLabel* label_BigIntTooBig) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_sign, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Uint32T> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, BigInt::kMaxLength);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block3, &block4, tmp0, tmp1, tmp2);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<Uint32T> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7);
    ca_.Goto(label_BigIntTooBig);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Uint32T> tmp9;
    TNode<IntPtrT> tmp10;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10);
    TNode<BigInt> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).AllocateBigInt(TNode<IntPtrT>{tmp10});
    BigIntBuiltinsAssembler(state_).WriteBigIntSignAndLength(TNode<BigInt>{tmp11}, TNode<Uint32T>{tmp9}, TNode<IntPtrT>{tmp10});
    ca_.Goto(&block5, tmp8, tmp9, tmp10, tmp11);
  }

    TNode<Context> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<BigInt> tmp15;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15);
  return TNode<BigInt>{tmp15};
}

TNode<BigInt> AllocateEmptyBigInt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_sign, TNode<IntPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT, Uint32T, IntPtrT, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT, Uint32T, IntPtrT, Context, BigInt> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, IntPtrT, BigInt> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_sign, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Uint32T> tmp1;
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = AllocateEmptyBigIntNoThrow_0(state_, TNode<Context>{tmp0}, TNode<Uint32T>{tmp1}, TNode<IntPtrT>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Uint32T> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Uint32T> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp4}, MessageTemplate::kBigIntTooBig);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<Uint32T> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Context> tmp15;
    TNode<BigInt> tmp16;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp10, tmp11, tmp12, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Uint32T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<BigInt> tmp20;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20);
  return TNode<BigInt>{tmp20};
}

TNode<Int32T> MutableBigIntAbsoluteCompare_0(compiler::CodeAssemblerState* state_, TNode<BigInt> p_x, TNode<BigInt> p_y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BigInt, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y);

  if (block0.is_used()) {
    TNode<BigInt> tmp0;
    TNode<BigInt> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = BigIntBuiltinsAssembler(state_).CppAbsoluteCompare(TNode<BigInt>{tmp0}, TNode<BigInt>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<BigInt> tmp3;
    TNode<BigInt> tmp4;
    TNode<Int32T> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<Int32T>{tmp5};
}

TNode<BigInt> MutableBigIntAbsoluteSub_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BigInt> p_x, TNode<BigInt> p_y, TNode<Uint32T> p_resultSign) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T, BigInt> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, Uint32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, BigInt> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, BigInt> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x, p_y, p_resultSign);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    TNode<Uint32T> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp1});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp2});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp1});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp7});
    ca_.Branch(tmp8, &block6, &block7, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<BigInt> tmp10;
    TNode<BigInt> tmp11;
    TNode<Uint32T> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Uint32T> tmp15;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'MutableBigIntAbsoluteCompare(x, y) >= 0' failed", "src/builtins/bigint.tq", 91);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<BigInt> tmp17;
    TNode<BigInt> tmp18;
    TNode<Uint32T> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Uint32T> tmp22;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
  }

  if (block6.is_used()) {
    TNode<Context> tmp23;
    TNode<BigInt> tmp24;
    TNode<BigInt> tmp25;
    TNode<Uint32T> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<Uint32T> tmp29;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block1, tmp23, tmp24, tmp25, tmp26, tmp24);
  }

  if (block11.is_used()) {
    TNode<Context> tmp30;
    TNode<BigInt> tmp31;
    TNode<BigInt> tmp32;
    TNode<Uint32T> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Uint32T> tmp36;
    ca_.Bind(&block11, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ylength == 0' failed", "src/builtins/bigint.tq", 93);
  }

  if (block10.is_used()) {
    TNode<Context> tmp37;
    TNode<BigInt> tmp38;
    TNode<BigInt> tmp39;
    TNode<Uint32T> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<Uint32T> tmp43;
    ca_.Bind(&block10, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
  }

  if (block7.is_used()) {
    TNode<Context> tmp44;
    TNode<BigInt> tmp45;
    TNode<BigInt> tmp46;
    TNode<Uint32T> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<Uint32T> tmp50;
    ca_.Bind(&block7, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp49}, TNode<IntPtrT>{tmp51});
    ca_.Branch(tmp52, &block12, &block13, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50);
  }

  if (block12.is_used()) {
    TNode<Context> tmp53;
    TNode<BigInt> tmp54;
    TNode<BigInt> tmp55;
    TNode<Uint32T> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Uint32T> tmp59;
    ca_.Bind(&block12, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp56}, TNode<Uint32T>{tmp59});
    ca_.Branch(tmp60, &block14, &block15, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59);
  }

  if (block14.is_used()) {
    TNode<Context> tmp61;
    TNode<BigInt> tmp62;
    TNode<BigInt> tmp63;
    TNode<Uint32T> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<Uint32T> tmp67;
    ca_.Bind(&block14, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    ca_.Goto(&block16, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp62);
  }

  if (block15.is_used()) {
    TNode<Context> tmp68;
    TNode<BigInt> tmp69;
    TNode<BigInt> tmp70;
    TNode<Uint32T> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<Uint32T> tmp74;
    ca_.Bind(&block15, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<BigInt> tmp75;
    tmp75 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kBigIntUnaryMinus, tmp68, tmp69));
    USE(tmp75);
    ca_.Goto(&block16, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75);
  }

  if (block16.is_used()) {
    TNode<Context> tmp76;
    TNode<BigInt> tmp77;
    TNode<BigInt> tmp78;
    TNode<Uint32T> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<Uint32T> tmp82;
    TNode<BigInt> tmp83;
    ca_.Bind(&block16, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83);
    ca_.Goto(&block1, tmp76, tmp77, tmp78, tmp79, tmp83);
  }

  if (block13.is_used()) {
    TNode<Context> tmp84;
    TNode<BigInt> tmp85;
    TNode<BigInt> tmp86;
    TNode<Uint32T> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<Uint32T> tmp90;
    ca_.Bind(&block13, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<BigInt> tmp91;
    USE(tmp91);
    tmp91 = AllocateEmptyBigInt_0(state_, TNode<Context>{tmp84}, TNode<Uint32T>{tmp87}, TNode<IntPtrT>{tmp88});
    BigIntBuiltinsAssembler(state_).CppAbsoluteSubAndCanonicalize(TNode<BigInt>{tmp91}, TNode<BigInt>{tmp85}, TNode<BigInt>{tmp86});
    TNode<BigInt> tmp92;
    USE(tmp92);
    tmp92 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp91});
    ca_.Goto(&block1, tmp84, tmp85, tmp86, tmp87, tmp92);
  }

  if (block1.is_used()) {
    TNode<Context> tmp93;
    TNode<BigInt> tmp94;
    TNode<BigInt> tmp95;
    TNode<Uint32T> tmp96;
    TNode<BigInt> tmp97;
    ca_.Bind(&block1, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    ca_.Goto(&block18, tmp93, tmp94, tmp95, tmp96, tmp97);
  }

    TNode<Context> tmp98;
    TNode<BigInt> tmp99;
    TNode<BigInt> tmp100;
    TNode<Uint32T> tmp101;
    TNode<BigInt> tmp102;
    ca_.Bind(&block18, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
  return TNode<BigInt>{tmp102};
}

TNode<BigInt> MutableBigIntAbsoluteAdd_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BigInt> p_xBigint, TNode<BigInt> p_yBigint, TNode<Uint32T> p_resultSign, compiler::CodeAssemblerLabel* label_BigIntTooBig) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt, BigInt> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt, Uint32T, IntPtrT, Context> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, IntPtrT, IntPtrT, BigInt, BigInt, Uint32T, IntPtrT, Context, BigInt> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, BigInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, BigInt> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_xBigint, p_yBigint, p_resultSign);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    TNode<Uint32T> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp1});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp2});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp2);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<BigInt> tmp8;
    TNode<BigInt> tmp9;
    TNode<Uint32T> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<BigInt> tmp13;
    TNode<BigInt> tmp14;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block4, tmp7, tmp8, tmp9, tmp10, tmp12, tmp11, tmp9, tmp8);
  }

  if (block4.is_used()) {
    TNode<Context> tmp15;
    TNode<BigInt> tmp16;
    TNode<BigInt> tmp17;
    TNode<Uint32T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<BigInt> tmp21;
    TNode<BigInt> tmp22;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp23});
    ca_.Branch(tmp24, &block5, &block6, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22);
  }

  if (block5.is_used()) {
    TNode<Context> tmp25;
    TNode<BigInt> tmp26;
    TNode<BigInt> tmp27;
    TNode<Uint32T> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<BigInt> tmp31;
    TNode<BigInt> tmp32;
    ca_.Bind(&block5, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block2, tmp25, tmp26, tmp27, tmp28, tmp31);
  }

  if (block10.is_used()) {
    TNode<Context> tmp33;
    TNode<BigInt> tmp34;
    TNode<BigInt> tmp35;
    TNode<Uint32T> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<BigInt> tmp39;
    TNode<BigInt> tmp40;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ylength == 0' failed", "src/builtins/bigint.tq", 125);
  }

  if (block9.is_used()) {
    TNode<Context> tmp41;
    TNode<BigInt> tmp42;
    TNode<BigInt> tmp43;
    TNode<Uint32T> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<BigInt> tmp47;
    TNode<BigInt> tmp48;
    ca_.Bind(&block9, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
  }

  if (block6.is_used()) {
    TNode<Context> tmp49;
    TNode<BigInt> tmp50;
    TNode<BigInt> tmp51;
    TNode<Uint32T> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<BigInt> tmp55;
    TNode<BigInt> tmp56;
    ca_.Bind(&block6, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<IntPtrT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp54}, TNode<IntPtrT>{tmp57});
    ca_.Branch(tmp58, &block11, &block12, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56);
  }

  if (block11.is_used()) {
    TNode<Context> tmp59;
    TNode<BigInt> tmp60;
    TNode<BigInt> tmp61;
    TNode<Uint32T> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<BigInt> tmp65;
    TNode<BigInt> tmp66;
    ca_.Bind(&block11, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    TNode<Uint32T> tmp67;
    USE(tmp67);
    tmp67 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp65});
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp62}, TNode<Uint32T>{tmp67});
    ca_.Branch(tmp68, &block13, &block14, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66);
  }

  if (block13.is_used()) {
    TNode<Context> tmp69;
    TNode<BigInt> tmp70;
    TNode<BigInt> tmp71;
    TNode<Uint32T> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<BigInt> tmp75;
    TNode<BigInt> tmp76;
    ca_.Bind(&block13, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    ca_.Goto(&block15, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp75);
  }

  if (block14.is_used()) {
    TNode<Context> tmp77;
    TNode<BigInt> tmp78;
    TNode<BigInt> tmp79;
    TNode<Uint32T> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<BigInt> tmp83;
    TNode<BigInt> tmp84;
    ca_.Bind(&block14, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<BigInt> tmp85;
    tmp85 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kBigIntUnaryMinus, tmp77, tmp83));
    USE(tmp85);
    ca_.Goto(&block15, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block15.is_used()) {
    TNode<Context> tmp86;
    TNode<BigInt> tmp87;
    TNode<BigInt> tmp88;
    TNode<Uint32T> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<BigInt> tmp92;
    TNode<BigInt> tmp93;
    TNode<BigInt> tmp94;
    ca_.Bind(&block15, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    ca_.Goto(&block2, tmp86, tmp87, tmp88, tmp89, tmp94);
  }

  if (block12.is_used()) {
    TNode<Context> tmp95;
    TNode<BigInt> tmp96;
    TNode<BigInt> tmp97;
    TNode<Uint32T> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<BigInt> tmp101;
    TNode<BigInt> tmp102;
    ca_.Bind(&block12, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    TNode<IntPtrT> tmp103;
    USE(tmp103);
    tmp103 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp99}, TNode<IntPtrT>{tmp103});
    TNode<BigInt> tmp105;
    USE(tmp105);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp105 = AllocateEmptyBigIntNoThrow_0(state_, TNode<Context>{tmp95}, TNode<Uint32T>{tmp98}, TNode<IntPtrT>{tmp104}, &label0);
    ca_.Goto(&block17, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp98, tmp104, tmp95, tmp105);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp98, tmp104, tmp95);
    }
  }

  if (block18.is_used()) {
    TNode<Context> tmp106;
    TNode<BigInt> tmp107;
    TNode<BigInt> tmp108;
    TNode<Uint32T> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<BigInt> tmp112;
    TNode<BigInt> tmp113;
    TNode<Uint32T> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<Context> tmp116;
    ca_.Bind(&block18, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    ca_.Goto(label_BigIntTooBig);
  }

  if (block17.is_used()) {
    TNode<Context> tmp117;
    TNode<BigInt> tmp118;
    TNode<BigInt> tmp119;
    TNode<Uint32T> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<BigInt> tmp123;
    TNode<BigInt> tmp124;
    TNode<Uint32T> tmp125;
    TNode<IntPtrT> tmp126;
    TNode<Context> tmp127;
    TNode<BigInt> tmp128;
    ca_.Bind(&block17, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    BigIntBuiltinsAssembler(state_).CppAbsoluteAddAndCanonicalize(TNode<BigInt>{tmp128}, TNode<BigInt>{tmp123}, TNode<BigInt>{tmp124});
    TNode<BigInt> tmp129;
    USE(tmp129);
    tmp129 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp128});
    ca_.Goto(&block2, tmp117, tmp118, tmp119, tmp120, tmp129);
  }

  if (block2.is_used()) {
    TNode<Context> tmp130;
    TNode<BigInt> tmp131;
    TNode<BigInt> tmp132;
    TNode<Uint32T> tmp133;
    TNode<BigInt> tmp134;
    ca_.Bind(&block2, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
    ca_.Goto(&block19, tmp130, tmp131, tmp132, tmp133, tmp134);
  }

    TNode<Context> tmp135;
    TNode<BigInt> tmp136;
    TNode<BigInt> tmp137;
    TNode<Uint32T> tmp138;
    TNode<BigInt> tmp139;
    ca_.Bind(&block19, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139);
  return TNode<BigInt>{tmp139};
}

TNode<BigInt> BigIntAddImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BigInt> p_x, TNode<BigInt> p_y, compiler::CodeAssemblerLabel* label_BigIntTooBig) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T, BigInt, BigInt, Uint32T, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T, BigInt, BigInt, Uint32T, Context, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x, p_y);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Uint32T> tmp3;
    USE(tmp3);
    tmp3 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp1});
    TNode<Uint32T> tmp4;
    USE(tmp4);
    tmp4 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp2});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<BigInt> tmp7;
    TNode<BigInt> tmp8;
    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BigInt> tmp11;
    USE(tmp11);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp11 = MutableBigIntAbsoluteAdd_0(state_, TNode<Context>{tmp6}, TNode<BigInt>{tmp7}, TNode<BigInt>{tmp8}, TNode<Uint32T>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp8, tmp9, tmp10, tmp7, tmp8, tmp9, tmp6, tmp11);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp8, tmp9, tmp10, tmp7, tmp8, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<BigInt> tmp13;
    TNode<BigInt> tmp14;
    TNode<Uint32T> tmp15;
    TNode<Uint32T> tmp16;
    TNode<BigInt> tmp17;
    TNode<BigInt> tmp18;
    TNode<Uint32T> tmp19;
    TNode<Context> tmp20;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(label_BigIntTooBig);
  }

  if (block5.is_used()) {
    TNode<Context> tmp21;
    TNode<BigInt> tmp22;
    TNode<BigInt> tmp23;
    TNode<Uint32T> tmp24;
    TNode<Uint32T> tmp25;
    TNode<BigInt> tmp26;
    TNode<BigInt> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Context> tmp29;
    TNode<BigInt> tmp30;
    ca_.Bind(&block5, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block2, tmp21, tmp22, tmp23, tmp30);
  }

  if (block4.is_used()) {
    TNode<Context> tmp31;
    TNode<BigInt> tmp32;
    TNode<BigInt> tmp33;
    TNode<Uint32T> tmp34;
    TNode<Uint32T> tmp35;
    ca_.Bind(&block4, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<Int32T> tmp36;
    USE(tmp36);
    tmp36 = MutableBigIntAbsoluteCompare_0(state_, TNode<BigInt>{tmp32}, TNode<BigInt>{tmp33});
    TNode<Int32T> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).Int32GreaterThanOrEqual(TNode<Int32T>{tmp36}, TNode<Int32T>{tmp37});
    ca_.Branch(tmp38, &block7, &block8, tmp31, tmp32, tmp33, tmp34, tmp35);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<BigInt> tmp40;
    TNode<BigInt> tmp41;
    TNode<Uint32T> tmp42;
    TNode<Uint32T> tmp43;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BigInt> tmp44;
    USE(tmp44);
    tmp44 = MutableBigIntAbsoluteSub_0(state_, TNode<Context>{tmp39}, TNode<BigInt>{tmp40}, TNode<BigInt>{tmp41}, TNode<Uint32T>{tmp42});
    ca_.Goto(&block2, tmp39, tmp40, tmp41, tmp44);
  }

  if (block8.is_used()) {
    TNode<Context> tmp45;
    TNode<BigInt> tmp46;
    TNode<BigInt> tmp47;
    TNode<Uint32T> tmp48;
    TNode<Uint32T> tmp49;
    ca_.Bind(&block8, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Uint32T> tmp50;
    USE(tmp50);
    tmp50 = InvertSign_0(state_, TNode<Uint32T>{tmp48});
    TNode<BigInt> tmp51;
    USE(tmp51);
    tmp51 = MutableBigIntAbsoluteSub_0(state_, TNode<Context>{tmp45}, TNode<BigInt>{tmp47}, TNode<BigInt>{tmp46}, TNode<Uint32T>{tmp50});
    ca_.Goto(&block2, tmp45, tmp46, tmp47, tmp51);
  }

  if (block2.is_used()) {
    TNode<Context> tmp52;
    TNode<BigInt> tmp53;
    TNode<BigInt> tmp54;
    TNode<BigInt> tmp55;
    ca_.Bind(&block2, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block9, tmp52, tmp53, tmp54, tmp55);
  }

    TNode<Context> tmp56;
    TNode<BigInt> tmp57;
    TNode<BigInt> tmp58;
    TNode<BigInt> tmp59;
    ca_.Bind(&block9, &tmp56, &tmp57, &tmp58, &tmp59);
  return TNode<BigInt>{tmp59};
}

TF_BUILTIN(BigIntAddNoThrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<BigInt> parameter1 = UncheckedCast<BigInt>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<BigInt> parameter2 = UncheckedCast<BigInt>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt, BigInt, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt, BigInt, Context, BigInt> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = BigIntAddImpl_0(state_, TNode<Context>{tmp0}, TNode<BigInt>{tmp1}, TNode<BigInt>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<BigInt> tmp5;
    TNode<BigInt> tmp6;
    TNode<BigInt> tmp7;
    TNode<BigInt> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = Convert_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).Return(tmp10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<BigInt> tmp12;
    TNode<BigInt> tmp13;
    TNode<BigInt> tmp14;
    TNode<BigInt> tmp15;
    TNode<Context> tmp16;
    TNode<BigInt> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).Return(tmp17);
  }
}

TF_BUILTIN(BigIntAdd, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Numeric> parameter1 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Numeric> parameter2 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, Numeric, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, Numeric, Context, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, Numeric, Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, Numeric, Context, BigInt> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, BigInt, BigInt, BigInt, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, BigInt, BigInt, BigInt, Context, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Numeric> tmp1;
    TNode<Numeric> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_BigInt_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp4;
    TNode<Numeric> tmp5;
    TNode<Numeric> tmp6;
    TNode<Numeric> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block6, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block4, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Numeric> tmp10;
    TNode<Numeric> tmp11;
    TNode<Numeric> tmp12;
    TNode<Context> tmp13;
    TNode<BigInt> tmp14;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BigInt> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_BigInt_1(state_, TNode<Context>{tmp9}, TNode<Object>{tmp11}, &label0);
    ca_.Goto(&block7, tmp9, tmp10, tmp11, tmp14, tmp11, tmp9, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp9, tmp10, tmp11, tmp14, tmp11, tmp9);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<Numeric> tmp17;
    TNode<Numeric> tmp18;
    TNode<BigInt> tmp19;
    TNode<Numeric> tmp20;
    TNode<Context> tmp21;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block4, tmp16, tmp17, tmp18);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<Numeric> tmp23;
    TNode<Numeric> tmp24;
    TNode<BigInt> tmp25;
    TNode<Numeric> tmp26;
    TNode<Context> tmp27;
    TNode<BigInt> tmp28;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<BigInt> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = BigIntAddImpl_0(state_, TNode<Context>{tmp22}, TNode<BigInt>{tmp25}, TNode<BigInt>{tmp28}, &label0);
    ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp25, tmp28, tmp25, tmp28, tmp22, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp22, tmp23, tmp24, tmp25, tmp28, tmp25, tmp28, tmp22);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp30;
    TNode<Numeric> tmp31;
    TNode<Numeric> tmp32;
    TNode<BigInt> tmp33;
    TNode<BigInt> tmp34;
    TNode<BigInt> tmp35;
    TNode<BigInt> tmp36;
    TNode<Context> tmp37;
    ca_.Bind(&block10, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp30}, MessageTemplate::kBigIntTooBig);
  }

  if (block9.is_used()) {
    TNode<Context> tmp38;
    TNode<Numeric> tmp39;
    TNode<Numeric> tmp40;
    TNode<BigInt> tmp41;
    TNode<BigInt> tmp42;
    TNode<BigInt> tmp43;
    TNode<BigInt> tmp44;
    TNode<Context> tmp45;
    TNode<BigInt> tmp46;
    ca_.Bind(&block9, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    CodeStubAssembler(state_).Return(tmp46);
  }

  if (block4.is_used()) {
    TNode<Context> tmp47;
    TNode<Numeric> tmp48;
    TNode<Numeric> tmp49;
    ca_.Bind(&block4, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp47}, MessageTemplate::kBigIntMixedTypes);
  }
}

TNode<BigInt> BigIntSubtractImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BigInt> p_x, TNode<BigInt> p_y, compiler::CodeAssemblerLabel* label_BigIntTooBig) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T, BigInt, BigInt, Uint32T, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T, BigInt, BigInt, Uint32T, Context, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, Uint32T, Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x, p_y);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Uint32T> tmp3;
    USE(tmp3);
    tmp3 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp1});
    TNode<Uint32T> tmp4;
    USE(tmp4);
    tmp4 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp2});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<BigInt> tmp7;
    TNode<BigInt> tmp8;
    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BigInt> tmp11;
    USE(tmp11);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp11 = MutableBigIntAbsoluteAdd_0(state_, TNode<Context>{tmp6}, TNode<BigInt>{tmp7}, TNode<BigInt>{tmp8}, TNode<Uint32T>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp8, tmp9, tmp10, tmp7, tmp8, tmp9, tmp6, tmp11);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp8, tmp9, tmp10, tmp7, tmp8, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<BigInt> tmp13;
    TNode<BigInt> tmp14;
    TNode<Uint32T> tmp15;
    TNode<Uint32T> tmp16;
    TNode<BigInt> tmp17;
    TNode<BigInt> tmp18;
    TNode<Uint32T> tmp19;
    TNode<Context> tmp20;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(label_BigIntTooBig);
  }

  if (block5.is_used()) {
    TNode<Context> tmp21;
    TNode<BigInt> tmp22;
    TNode<BigInt> tmp23;
    TNode<Uint32T> tmp24;
    TNode<Uint32T> tmp25;
    TNode<BigInt> tmp26;
    TNode<BigInt> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Context> tmp29;
    TNode<BigInt> tmp30;
    ca_.Bind(&block5, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block2, tmp21, tmp22, tmp23, tmp30);
  }

  if (block4.is_used()) {
    TNode<Context> tmp31;
    TNode<BigInt> tmp32;
    TNode<BigInt> tmp33;
    TNode<Uint32T> tmp34;
    TNode<Uint32T> tmp35;
    ca_.Bind(&block4, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<Int32T> tmp36;
    USE(tmp36);
    tmp36 = MutableBigIntAbsoluteCompare_0(state_, TNode<BigInt>{tmp32}, TNode<BigInt>{tmp33});
    TNode<Int32T> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).Int32GreaterThanOrEqual(TNode<Int32T>{tmp36}, TNode<Int32T>{tmp37});
    ca_.Branch(tmp38, &block7, &block8, tmp31, tmp32, tmp33, tmp34, tmp35);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<BigInt> tmp40;
    TNode<BigInt> tmp41;
    TNode<Uint32T> tmp42;
    TNode<Uint32T> tmp43;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<BigInt> tmp44;
    USE(tmp44);
    tmp44 = MutableBigIntAbsoluteSub_0(state_, TNode<Context>{tmp39}, TNode<BigInt>{tmp40}, TNode<BigInt>{tmp41}, TNode<Uint32T>{tmp42});
    ca_.Goto(&block2, tmp39, tmp40, tmp41, tmp44);
  }

  if (block8.is_used()) {
    TNode<Context> tmp45;
    TNode<BigInt> tmp46;
    TNode<BigInt> tmp47;
    TNode<Uint32T> tmp48;
    TNode<Uint32T> tmp49;
    ca_.Bind(&block8, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Uint32T> tmp50;
    USE(tmp50);
    tmp50 = InvertSign_0(state_, TNode<Uint32T>{tmp48});
    TNode<BigInt> tmp51;
    USE(tmp51);
    tmp51 = MutableBigIntAbsoluteSub_0(state_, TNode<Context>{tmp45}, TNode<BigInt>{tmp47}, TNode<BigInt>{tmp46}, TNode<Uint32T>{tmp50});
    ca_.Goto(&block2, tmp45, tmp46, tmp47, tmp51);
  }

  if (block2.is_used()) {
    TNode<Context> tmp52;
    TNode<BigInt> tmp53;
    TNode<BigInt> tmp54;
    TNode<BigInt> tmp55;
    ca_.Bind(&block2, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block9, tmp52, tmp53, tmp54, tmp55);
  }

    TNode<Context> tmp56;
    TNode<BigInt> tmp57;
    TNode<BigInt> tmp58;
    TNode<BigInt> tmp59;
    ca_.Bind(&block9, &tmp56, &tmp57, &tmp58, &tmp59);
  return TNode<BigInt>{tmp59};
}

TF_BUILTIN(BigIntSubtractNoThrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<BigInt> parameter1 = UncheckedCast<BigInt>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<BigInt> parameter2 = UncheckedCast<BigInt>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt, BigInt, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, BigInt, BigInt, BigInt, Context, BigInt> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = BigIntSubtractImpl_0(state_, TNode<Context>{tmp0}, TNode<BigInt>{tmp1}, TNode<BigInt>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<BigInt> tmp5;
    TNode<BigInt> tmp6;
    TNode<BigInt> tmp7;
    TNode<BigInt> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = Convert_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).Return(tmp10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<BigInt> tmp12;
    TNode<BigInt> tmp13;
    TNode<BigInt> tmp14;
    TNode<BigInt> tmp15;
    TNode<Context> tmp16;
    TNode<BigInt> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).Return(tmp17);
  }
}

TF_BUILTIN(BigIntSubtract, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Numeric> parameter1 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Numeric> parameter2 = UncheckedCast<Numeric>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, Numeric, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, Numeric, Context, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, Numeric, Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, Numeric, Context, BigInt> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, BigInt, BigInt, BigInt, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric, BigInt, BigInt, BigInt, BigInt, Context, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Numeric, Numeric> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Numeric> tmp1;
    TNode<Numeric> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_BigInt_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp4;
    TNode<Numeric> tmp5;
    TNode<Numeric> tmp6;
    TNode<Numeric> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block6, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block4, tmp4, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Numeric> tmp10;
    TNode<Numeric> tmp11;
    TNode<Numeric> tmp12;
    TNode<Context> tmp13;
    TNode<BigInt> tmp14;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BigInt> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_BigInt_1(state_, TNode<Context>{tmp9}, TNode<Object>{tmp11}, &label0);
    ca_.Goto(&block7, tmp9, tmp10, tmp11, tmp14, tmp11, tmp9, tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp9, tmp10, tmp11, tmp14, tmp11, tmp9);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<Numeric> tmp17;
    TNode<Numeric> tmp18;
    TNode<BigInt> tmp19;
    TNode<Numeric> tmp20;
    TNode<Context> tmp21;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block4, tmp16, tmp17, tmp18);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<Numeric> tmp23;
    TNode<Numeric> tmp24;
    TNode<BigInt> tmp25;
    TNode<Numeric> tmp26;
    TNode<Context> tmp27;
    TNode<BigInt> tmp28;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<BigInt> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = BigIntSubtractImpl_0(state_, TNode<Context>{tmp22}, TNode<BigInt>{tmp25}, TNode<BigInt>{tmp28}, &label0);
    ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp25, tmp28, tmp25, tmp28, tmp22, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp22, tmp23, tmp24, tmp25, tmp28, tmp25, tmp28, tmp22);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp30;
    TNode<Numeric> tmp31;
    TNode<Numeric> tmp32;
    TNode<BigInt> tmp33;
    TNode<BigInt> tmp34;
    TNode<BigInt> tmp35;
    TNode<BigInt> tmp36;
    TNode<Context> tmp37;
    ca_.Bind(&block10, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp30}, MessageTemplate::kBigIntTooBig);
  }

  if (block9.is_used()) {
    TNode<Context> tmp38;
    TNode<Numeric> tmp39;
    TNode<Numeric> tmp40;
    TNode<BigInt> tmp41;
    TNode<BigInt> tmp42;
    TNode<BigInt> tmp43;
    TNode<BigInt> tmp44;
    TNode<Context> tmp45;
    TNode<BigInt> tmp46;
    ca_.Bind(&block9, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    CodeStubAssembler(state_).Return(tmp46);
  }

  if (block4.is_used()) {
    TNode<Context> tmp47;
    TNode<Numeric> tmp48;
    TNode<Numeric> tmp49;
    ca_.Bind(&block4, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp47}, MessageTemplate::kBigIntMixedTypes);
  }
}

TF_BUILTIN(BigIntUnaryMinus, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<BigInt> parameter1 = UncheckedCast<BigInt>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, IntPtrT, BigInt, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, IntPtrT, BigInt, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BigInt, IntPtrT, BigInt, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<BigInt> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block1, &block2, tmp0, tmp1, tmp2);
  }

  if (block1.is_used()) {
    TNode<Context> tmp5;
    TNode<BigInt> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block1, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<BigInt> tmp9;
    TNode<IntPtrT> tmp10;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10);
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp9});
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = InvertSign_0(state_, TNode<Uint32T>{tmp11});
    TNode<BigInt> tmp13;
    USE(tmp13);
    tmp13 = AllocateEmptyBigInt_0(state_, TNode<Context>{tmp8}, TNode<Uint32T>{tmp12}, TNode<IntPtrT>{tmp10});
    TNode<IntPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block5, tmp8, tmp9, tmp10, tmp13, tmp14);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<BigInt> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<BigInt> tmp18;
    TNode<IntPtrT> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp17});
    ca_.Branch(tmp20, &block3, &block4, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<Context> tmp21;
    TNode<BigInt> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<BigInt> tmp24;
    TNode<IntPtrT> tmp25;
    ca_.Bind(&block3, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<UintPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp22}, TNode<IntPtrT>{tmp25});
    CodeStubAssembler(state_).StoreBigIntDigit(TNode<BigInt>{tmp24}, TNode<IntPtrT>{tmp25}, TNode<UintPtrT>{tmp26});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp27});
    ca_.Goto(&block5, tmp21, tmp22, tmp23, tmp24, tmp28);
  }

  if (block4.is_used()) {
    TNode<Context> tmp29;
    TNode<BigInt> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<BigInt> tmp32;
    TNode<IntPtrT> tmp33;
    ca_.Bind(&block4, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<BigInt> tmp34;
    USE(tmp34);
    tmp34 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp32});
    CodeStubAssembler(state_).Return(tmp34);
  }
}

TNode<BigInt> Convert_BigIntBase_MutableBigInt_0(compiler::CodeAssemblerState* state_, TNode<BigInt> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BigInt> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BigInt, BigInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<BigInt> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<BigInt> tmp1;
    TNode<BigInt> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<BigInt>{tmp2};
}

TNode<BigInt> Cast_BigInt_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BigInt> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<BigInt> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_BigInt_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<BigInt> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<BigInt> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<BigInt>{tmp20};
}

}  // namespace internal
}  // namespace v8

