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

TNode<UintPtrT> kSmiMax_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<UintPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
return TNode<UintPtrT>{tmp0};
}

TNode<Oddball> TheHole_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).TheHoleConstant();
return TNode<Oddball>{tmp0};
}

TNode<Oddball> Null_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).NullConstant();
return TNode<Oddball>{tmp0};
}

TNode<Oddball> Undefined_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).UndefinedConstant();
return TNode<Oddball>{tmp0};
}

TNode<Oddball> True_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).TrueConstant();
return TNode<Oddball>{tmp0};
}

TNode<Oddball> False_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).FalseConstant();
return TNode<Oddball>{tmp0};
}

TNode<String> kEmptyString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).EmptyStringConstant();
return TNode<String>{tmp0};
}

TNode<String> kLengthString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).LengthStringConstant();
return TNode<String>{tmp0};
}

TNode<HeapNumber> kNaN_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<HeapNumber> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).NanConstant();
return TNode<HeapNumber>{tmp0};
}

TNode<Smi> kZero_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Smi>{tmp0});
return TNode<Smi>{tmp1};
}

TF_BUILTIN(ToString, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = ToStringImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TNode<Object> ToPrimitiveDefault_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_v);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    ca_.Goto(&block1, tmp3, tmp4, ca_.UncheckedCast<Object>(tmp5));
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Context> tmp12;
    TNode<JSReceiver> tmp13;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<Object> tmp14;
    tmp14 = CodeStubAssembler(state_).CallBuiltin(Builtins::kNonPrimitiveToPrimitive_Default, tmp8, tmp13);
    USE(tmp14);
    ca_.Goto(&block1, tmp8, tmp9, tmp14);
  }

  if (block1.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block1, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block6, tmp15, tmp16, tmp17);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block6, &tmp18, &tmp19, &tmp20);
  return TNode<Object>{tmp20};
}

TNode<BoolT> ElementsKindNotEqual_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_k1, TNode<Int32T> p_k2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_k1, p_k2);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp3);
  }

    TNode<Int32T> tmp4;
    TNode<Int32T> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
  return TNode<BoolT>{tmp6};
}

TNode<BoolT> IsNumberEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfNumberEqual(TNode<Number>{tmp0}, TNode<Number>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0, tmp1);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, tmp1);
    }
  }

  if (block6.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Number> tmp15;
    TNode<Number> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> IsNumberNotEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsNumberEqual_0(state_, TNode<Number>{tmp0}, TNode<Number>{tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp3);
  }

    TNode<Number> tmp4;
    TNode<Number> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
  return TNode<BoolT>{tmp6};
}

TNode<BoolT> NumberIsLessThan_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfNumberLessThan(TNode<Number>{tmp0}, TNode<Number>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0, tmp1);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, tmp1);
    }
  }

  if (block6.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Number> tmp15;
    TNode<Number> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> NumberIsLessThanOrEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfNumberLessThanOrEqual(TNode<Number>{tmp0}, TNode<Number>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0, tmp1);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, tmp1);
    }
  }

  if (block6.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Number> tmp15;
    TNode<Number> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> NumberIsGreaterThan_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = NumberIsLessThan_0(state_, TNode<Number>{tmp1}, TNode<Number>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<BoolT> NumberIsGreaterThanOrEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = NumberIsLessThanOrEqual_0(state_, TNode<Number>{tmp1}, TNode<Number>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<BoolT> Float64IsNaN_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, Float64T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_n);

  if (block0.is_used()) {
    TNode<Float64T> tmp0;
    ca_.Bind(&block0, &tmp0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfFloat64IsNaN(TNode<Float64T>{tmp0}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    ca_.Bind(&block6, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp1, tmp3);
  }

  if (block7.is_used()) {
    TNode<Float64T> tmp4;
    TNode<Float64T> tmp5;
    ca_.Bind(&block7, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4, tmp6);
  }

  if (block1.is_used()) {
    TNode<Float64T> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block1, &tmp7, &tmp8);
    ca_.Goto(&block8, tmp7, tmp8);
  }

    TNode<Float64T> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block8, &tmp9, &tmp10);
  return TNode<BoolT>{tmp10};
}

TNode<Number> Min_0(compiler::CodeAssemblerState* state_, TNode<Number> p_x, TNode<Number> p_y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).NumberMin(TNode<Number>{tmp0}, TNode<Number>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<Number>{tmp5};
}

TNode<Number> Max_0(compiler::CodeAssemblerState* state_, TNode<Number> p_x, TNode<Number> p_y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).NumberMax(TNode<Number>{tmp0}, TNode<Number>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<Number>{tmp5};
}

TNode<UintPtrT> LoadJSArrayLengthAsUintPtr_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<UintPtrT> tmp3;
    USE(tmp3);
    tmp3 = Convert_uintptr_Number_0(state_, TNode<Number>{tmp2});
    ca_.Goto(&block2, tmp0, tmp3);
  }

    TNode<JSArray> tmp4;
    TNode<UintPtrT> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
  return TNode<UintPtrT>{tmp5};
}

TNode<UintPtrT> LoadStringLengthAsUintPtr_0(compiler::CodeAssemblerState* state_, TNode<String> p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_s);

  if (block0.is_used()) {
    TNode<String> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp0});
    TNode<UintPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<String> tmp3;
    TNode<UintPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<UintPtrT>{tmp4};
}

TNode<String> StringAdd_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_a, TNode<String> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_b);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<String> tmp3;
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringAdd_CheckNone, tmp0, tmp1, tmp2));
    USE(tmp3);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<Context> tmp4;
    TNode<String> tmp5;
    TNode<String> tmp6;
    TNode<String> tmp7;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6, &tmp7);
  return TNode<String>{tmp7};
}

TNode<BoolT> PromiseStateEquals_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_s1, TNode<Int32T> p_s2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_s1, p_s2);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Int32T> tmp3;
    TNode<Int32T> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<Map> kFixedArrayMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).FixedArrayMapConstant();
return TNode<Map>{tmp0};
}

TNode<Map> kCOWMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).FixedCOWArrayMapConstant();
return TNode<Map>{tmp0};
}

TNode<ByteArray> kEmptyByteArray_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<ByteArray> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).EmptyByteArrayConstant();
return TNode<ByteArray>{tmp0};
}

TNode<FixedArray> kEmptyFixedArray_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<FixedArray> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).EmptyFixedArrayConstant();
return TNode<FixedArray>{tmp0};
}

TNode<Map> kPromiseCapabilityMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).PromiseCapabilityMapConstant();
return TNode<Map>{tmp0};
}

void StoreFastJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array, TNode<Smi> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_array, p_length);

  if (block0.is_used()) {
    TNode<JSArray> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSArray> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Int32T> FastHoleyElementsKind_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_kind);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_SMI_ELEMENTS);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_SMI_ELEMENTS);
    ca_.Goto(&block1, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Int32T> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_DOUBLE_ELEMENTS);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block5, &block6, tmp5);
  }

  if (block5.is_used()) {
    TNode<Int32T> tmp8;
    ca_.Bind(&block5, &tmp8);
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_DOUBLE_ELEMENTS);
    ca_.Goto(&block1, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Int32T> tmp10;
    ca_.Bind(&block6, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_ELEMENTS);
    ca_.Goto(&block1, tmp10, tmp11);
  }

  if (block10.is_used()) {
    TNode<Int32T> tmp12;
    ca_.Bind(&block10, &tmp12);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kind == PACKED_ELEMENTS' failed", "src/builtins/base.tq", 973);
  }

  if (block9.is_used()) {
    TNode<Int32T> tmp13;
    ca_.Bind(&block9, &tmp13);
  }

  if (block1.is_used()) {
    TNode<Int32T> tmp14;
    TNode<Int32T> tmp15;
    ca_.Bind(&block1, &tmp14, &tmp15);
    ca_.Goto(&block11, tmp14, tmp15);
  }

    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    ca_.Bind(&block11, &tmp16, &tmp17);
  return TNode<Int32T>{tmp17};
}

TNode<Int32T> AllowDoubleElements_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_kind);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_SMI_ELEMENTS);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_DOUBLE_ELEMENTS);
    ca_.Goto(&block1, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Int32T> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_SMI_ELEMENTS);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block5, &block6, tmp5);
  }

  if (block5.is_used()) {
    TNode<Int32T> tmp8;
    ca_.Bind(&block5, &tmp8);
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_DOUBLE_ELEMENTS);
    ca_.Goto(&block1, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Int32T> tmp10;
    ca_.Bind(&block6, &tmp10);
    ca_.Goto(&block1, tmp10, tmp10);
  }

  if (block1.is_used()) {
    TNode<Int32T> tmp11;
    TNode<Int32T> tmp12;
    ca_.Bind(&block1, &tmp11, &tmp12);
    ca_.Goto(&block7, tmp11, tmp12);
  }

    TNode<Int32T> tmp13;
    TNode<Int32T> tmp14;
    ca_.Bind(&block7, &tmp13, &tmp14);
  return TNode<Int32T>{tmp14};
}

TNode<Int32T> AllowNonNumberElements_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_kind);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_SMI_ELEMENTS);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_ELEMENTS);
    ca_.Goto(&block1, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Int32T> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_SMI_ELEMENTS);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block5, &block6, tmp5);
  }

  if (block5.is_used()) {
    TNode<Int32T> tmp8;
    ca_.Bind(&block5, &tmp8);
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_ELEMENTS);
    ca_.Goto(&block1, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Int32T> tmp10;
    ca_.Bind(&block6, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_DOUBLE_ELEMENTS);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp10}, TNode<Int32T>{tmp11});
    ca_.Branch(tmp12, &block8, &block9, tmp10);
  }

  if (block8.is_used()) {
    TNode<Int32T> tmp13;
    ca_.Bind(&block8, &tmp13);
    TNode<Int32T> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, PACKED_ELEMENTS);
    ca_.Goto(&block1, tmp13, tmp14);
  }

  if (block9.is_used()) {
    TNode<Int32T> tmp15;
    ca_.Bind(&block9, &tmp15);
    TNode<Int32T> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_DOUBLE_ELEMENTS);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).ElementsKindEqual(TNode<Int32T>{tmp15}, TNode<Int32T>{tmp16});
    ca_.Branch(tmp17, &block11, &block12, tmp15);
  }

  if (block11.is_used()) {
    TNode<Int32T> tmp18;
    ca_.Bind(&block11, &tmp18);
    TNode<Int32T> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_ElementsKind_constexpr_ElementsKind_0(state_, HOLEY_ELEMENTS);
    ca_.Goto(&block1, tmp18, tmp19);
  }

  if (block12.is_used()) {
    TNode<Int32T> tmp20;
    ca_.Bind(&block12, &tmp20);
    ca_.Goto(&block1, tmp20, tmp20);
  }

  if (block1.is_used()) {
    TNode<Int32T> tmp21;
    TNode<Int32T> tmp22;
    ca_.Bind(&block1, &tmp21, &tmp22);
    ca_.Goto(&block13, tmp21, tmp22);
  }

    TNode<Int32T> tmp23;
    TNode<Int32T> tmp24;
    ca_.Bind(&block13, &tmp23, &tmp24);
  return TNode<Int32T>{tmp24};
}

TNode<JSFunction> GetObjectFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::OBJECT_FUNCTION_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSFunction> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<JSFunction>{tmp6};
}

TNode<JSReceiver> GetArrayBufferFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::ARRAY_BUFFER_FUN_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<JSReceiver>{tmp6};
}

TNode<JSFunction> GetArrayBufferNoInitFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::ARRAY_BUFFER_NOINIT_FUN_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSFunction> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<JSFunction>{tmp6};
}

TNode<Map> GetFastPackedElementsJSArrayMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<Map>{tmp6};
}

TNode<Map> GetFastPackedSmiElementsJSArrayMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<Map>{tmp6};
}

TNode<Map> GetProxyRevocableResultMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::PROXY_REVOCABLE_RESULT_MAP_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<Map>{tmp6};
}

TNode<Map> GetIteratorResultMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::ITERATOR_RESULT_MAP_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<Map>{tmp6};
}

TNode<Map> GetInitialStringIteratorMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::INITIAL_STRING_ITERATOR_MAP_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<Map> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<Map>{tmp6};
}

TNode<JSReceiver> GetReflectApply_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::REFLECT_APPLY_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<JSReceiver>{tmp6};
}

TNode<RegExpMatchInfo> GetRegExpLastMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RegExpMatchInfo> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<NativeContext> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::REGEXP_LAST_MATCH_INFO_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<RegExpMatchInfo> tmp4;
    USE(tmp4);
    tmp4 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp4);
  }

    TNode<Context> tmp5;
    TNode<RegExpMatchInfo> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
  return TNode<RegExpMatchInfo>{tmp6};
}

TNode<BoolT> NumberIsNaN_0(compiler::CodeAssemblerState* state_, TNode<Number> p_number) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_number);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    TNode<Float64T> tmp5;
    USE(tmp5);
    tmp5 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp3)});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Float64NotEqual(TNode<Float64T>{tmp5}, TNode<Float64T>{tmp5});
    ca_.Goto(&block1, tmp2, tmp6);
  }

  if (block4.is_used()) {
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp11);
  }

  if (block1.is_used()) {
    TNode<Number> tmp12;
    TNode<BoolT> tmp13;
    ca_.Bind(&block1, &tmp12, &tmp13);
    ca_.Goto(&block6, tmp12, tmp13);
  }

    TNode<Number> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block6, &tmp14, &tmp15);
  return TNode<BoolT>{tmp15};
}

TNode<BoolT> IsForceSlowPath_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    CodeStubAssembler(state_).GotoIfForceSlowPath(&label0);
    ca_.Goto(&block4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  if (block1.is_used()) {
    TNode<BoolT> tmp2;
    ca_.Bind(&block1, &tmp2);
    ca_.Goto(&block6, tmp2);
  }

    TNode<BoolT> tmp3;
    ca_.Bind(&block6, &tmp3);
  return TNode<BoolT>{tmp3};
}

TNode<BoolT> ToBoolean_0(compiler::CodeAssemblerState* state_, TNode<Object> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_obj);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfToBooleanIsTrue(TNode<Object>{tmp0}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block6, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp1, tmp3);
  }

  if (block7.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block7, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4, tmp6);
  }

  if (block1.is_used()) {
    TNode<Object> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block1, &tmp7, &tmp8);
    ca_.Goto(&block8, tmp7, tmp8);
  }

    TNode<Object> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block8, &tmp9, &tmp10);
  return TNode<BoolT>{tmp10};
}

TNode<Object> RequireObjectCoercible_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, const char* p_name) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsNullOrUndefined(TNode<Object>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp3}, MessageTemplate::kCalledOnNullOrUndefined, p_name);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block3, &tmp5, &tmp6);
    ca_.Goto(&block4, tmp5, tmp6, tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9);
  return TNode<Object>{tmp9};
}

TNode<BoolT> SameValue_0(compiler::CodeAssemblerState* state_, TNode<Object> p_a, TNode<Object> p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_b);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    CodeStubAssembler(state_).BranchIfSameValue(TNode<Object>{tmp0}, TNode<Object>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0, tmp1);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, tmp1);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

void CheckIntegerIndexAdditionOverflow_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_index1, TNode<UintPtrT> p_index2, TNode<UintPtrT> p_limit, compiler::CodeAssemblerLabel* label_IfOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_index1, p_index2, p_limit);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block3, tmp0, tmp1, tmp2);
    } else {
      ca_.Goto(&block4, tmp0, tmp1, tmp2);
    }
  }

  if (block3.is_used()) {
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<UintPtrT> tmp5;
    ca_.Bind(&block3, &tmp3, &tmp4, &tmp5);
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp7, &block14, &block15, tmp3, tmp4, tmp5);
  }

  if (block9.is_used()) {
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<UintPtrT> tmp10;
    ca_.Bind(&block9, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index1 <= kMaxSafeIntegerUint64' failed", "src/builtins/base.tq", 1102);
  }

  if (block8.is_used()) {
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<UintPtrT> tmp13;
    ca_.Bind(&block8, &tmp11, &tmp12, &tmp13);
  }

  if (block13.is_used()) {
    TNode<UintPtrT> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<UintPtrT> tmp16;
    ca_.Bind(&block13, &tmp14, &tmp15, &tmp16);
    CodeStubAssembler(state_).FailAssert("Torque assert 'index2 <= kMaxSafeIntegerUint64' failed", "src/builtins/base.tq", 1103);
  }

  if (block12.is_used()) {
    TNode<UintPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    ca_.Bind(&block12, &tmp17, &tmp18, &tmp19);
  }

  if (block14.is_used()) {
    TNode<UintPtrT> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<UintPtrT> tmp22;
    ca_.Bind(&block14, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block1);
  }

  if (block15.is_used()) {
    TNode<UintPtrT> tmp23;
    TNode<UintPtrT> tmp24;
    TNode<UintPtrT> tmp25;
    ca_.Bind(&block15, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block5, tmp23, tmp24, tmp25);
  }

  if (block4.is_used()) {
    TNode<UintPtrT> tmp26;
    TNode<UintPtrT> tmp27;
    TNode<UintPtrT> tmp28;
    ca_.Bind(&block4, &tmp26, &tmp27, &tmp28);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp28}, TNode<UintPtrT>{tmp27});
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp26}, TNode<UintPtrT>{tmp29});
    ca_.Branch(tmp30, &block16, &block17, tmp26, tmp27, tmp28, tmp29);
  }

  if (block16.is_used()) {
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<UintPtrT> tmp34;
    ca_.Bind(&block16, &tmp31, &tmp32, &tmp33, &tmp34);
    ca_.Goto(&block1);
  }

  if (block17.is_used()) {
    TNode<UintPtrT> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<UintPtrT> tmp37;
    TNode<UintPtrT> tmp38;
    ca_.Bind(&block17, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp38}, TNode<UintPtrT>{tmp37});
    ca_.Branch(tmp39, &block18, &block19, tmp35, tmp36, tmp37, tmp38);
  }

  if (block18.is_used()) {
    TNode<UintPtrT> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<UintPtrT> tmp43;
    ca_.Bind(&block18, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block1);
  }

  if (block19.is_used()) {
    TNode<UintPtrT> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<UintPtrT> tmp46;
    TNode<UintPtrT> tmp47;
    ca_.Bind(&block19, &tmp44, &tmp45, &tmp46, &tmp47);
    ca_.Goto(&block5, tmp44, tmp45, tmp46);
  }

  if (block5.is_used()) {
    TNode<UintPtrT> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<UintPtrT> tmp50;
    ca_.Bind(&block5, &tmp48, &tmp49, &tmp50);
    ca_.Goto(&block20, tmp48, tmp49, tmp50);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfOverflow);
  }

    TNode<UintPtrT> tmp51;
    TNode<UintPtrT> tmp52;
    TNode<UintPtrT> tmp53;
    ca_.Bind(&block20, &tmp51, &tmp52, &tmp53);
}

int31_t kModeValueIsSafeIntegerUintPtr_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 0;
}

int31_t kModeValueIsSafeInteger_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 1;
}

int31_t kModeValueIsAnyNumber_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 2;
}

TNode<UintPtrT> TryNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_valueNumber, int31_t p_kMode, compiler::CodeAssemblerLabel* label_IfLessThanZero, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow, compiler::CodeAssemblerLabel* label_IfSafeIntegerOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, HeapNumber, Float64T> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_valueNumber);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block7, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp0, tmp0, tmp0);
    }
  }

  if (block8.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block8, &tmp2, &tmp3, &tmp4);
    TNode<Float64T> tmp5;
    USE(tmp5);
    tmp5 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp3)});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_kMode, kModeValueIsAnyNumber_0(state_))));
    ca_.Branch(tmp6, &block26, &block27, tmp2, tmp3, ca_.UncheckedCast<HeapNumber>(tmp3), tmp5);
  }

  if (block7.is_used()) {
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_kMode, kModeValueIsAnyNumber_0(state_))));
    ca_.Branch(tmp11, &block9, &block10, tmp7, tmp8, tmp10);
  }

  if (block9.is_used()) {
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block9, &tmp12, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp14}, TNode<Smi>{tmp15});
    ca_.Branch(tmp16, &block12, &block13, tmp12, tmp13, tmp14);
  }

  if (block12.is_used()) {
    TNode<Number> tmp17;
    TNode<Number> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block12, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block1);
  }

  if (block13.is_used()) {
    TNode<Number> tmp20;
    TNode<Number> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block13, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block11, tmp20, tmp21, tmp22);
  }

  if (block10.is_used()) {
    TNode<Number> tmp23;
    TNode<Number> tmp24;
    TNode<Smi> tmp25;
    ca_.Bind(&block10, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block11, tmp23, tmp24, tmp25);
  }

  if (block17.is_used()) {
    TNode<Number> tmp26;
    TNode<Number> tmp27;
    TNode<Smi> tmp28;
    ca_.Bind(&block17, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'valueSmi >= 0' failed", "src/builtins/base.tq", 1137);
  }

  if (block16.is_used()) {
    TNode<Number> tmp29;
    TNode<Number> tmp30;
    TNode<Smi> tmp31;
    ca_.Bind(&block16, &tmp29, &tmp30, &tmp31);
  }

  if (block11.is_used()) {
    TNode<Number> tmp32;
    TNode<Number> tmp33;
    TNode<Smi> tmp34;
    ca_.Bind(&block11, &tmp32, &tmp33, &tmp34);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp34});
    TNode<UintPtrT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp35});
    ca_.Goto(&block4, tmp32, tmp36);
  }

  if (block21.is_used()) {
    TNode<Number> tmp37;
    TNode<Number> tmp38;
    TNode<HeapNumber> tmp39;
    ca_.Bind(&block21, &tmp37, &tmp38, &tmp39);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(valueHeapNumber)' failed", "src/builtins/base.tq", 1145);
  }

  if (block20.is_used()) {
    TNode<Number> tmp40;
    TNode<Number> tmp41;
    TNode<HeapNumber> tmp42;
    ca_.Bind(&block20, &tmp40, &tmp41, &tmp42);
  }

  if (block25.is_used()) {
    TNode<Number> tmp43;
    TNode<Number> tmp44;
    TNode<HeapNumber> tmp45;
    TNode<Float64T> tmp46;
    ca_.Bind(&block25, &tmp43, &tmp44, &tmp45, &tmp46);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Float64IsNaN(valueDouble)' failed", "src/builtins/base.tq", 1148);
  }

  if (block24.is_used()) {
    TNode<Number> tmp47;
    TNode<Number> tmp48;
    TNode<HeapNumber> tmp49;
    TNode<Float64T> tmp50;
    ca_.Bind(&block24, &tmp47, &tmp48, &tmp49, &tmp50);
  }

  if (block26.is_used()) {
    TNode<Number> tmp51;
    TNode<Number> tmp52;
    TNode<HeapNumber> tmp53;
    TNode<Float64T> tmp54;
    ca_.Bind(&block26, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<Float64T> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp54}, TNode<Float64T>{tmp55});
    ca_.Branch(tmp56, &block29, &block30, tmp51, tmp52, tmp53, tmp54);
  }

  if (block29.is_used()) {
    TNode<Number> tmp57;
    TNode<Number> tmp58;
    TNode<HeapNumber> tmp59;
    TNode<Float64T> tmp60;
    ca_.Bind(&block29, &tmp57, &tmp58, &tmp59, &tmp60);
    ca_.Goto(&block1);
  }

  if (block30.is_used()) {
    TNode<Number> tmp61;
    TNode<Number> tmp62;
    TNode<HeapNumber> tmp63;
    TNode<Float64T> tmp64;
    ca_.Bind(&block30, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Goto(&block28, tmp61, tmp62, tmp63, tmp64);
  }

  if (block27.is_used()) {
    TNode<Number> tmp65;
    TNode<Number> tmp66;
    TNode<HeapNumber> tmp67;
    TNode<Float64T> tmp68;
    ca_.Bind(&block27, &tmp65, &tmp66, &tmp67, &tmp68);
    ca_.Goto(&block28, tmp65, tmp66, tmp67, tmp68);
  }

  if (block34.is_used()) {
    TNode<Number> tmp69;
    TNode<Number> tmp70;
    TNode<HeapNumber> tmp71;
    TNode<Float64T> tmp72;
    ca_.Bind(&block34, &tmp69, &tmp70, &tmp71, &tmp72);
    CodeStubAssembler(state_).FailAssert("Torque assert 'valueDouble >= 0' failed", "src/builtins/base.tq", 1152);
  }

  if (block33.is_used()) {
    TNode<Number> tmp73;
    TNode<Number> tmp74;
    TNode<HeapNumber> tmp75;
    TNode<Float64T> tmp76;
    ca_.Bind(&block33, &tmp73, &tmp74, &tmp75, &tmp76);
  }

  if (block28.is_used()) {
    TNode<Number> tmp77;
    TNode<Number> tmp78;
    TNode<HeapNumber> tmp79;
    TNode<Float64T> tmp80;
    ca_.Bind(&block28, &tmp77, &tmp78, &tmp79, &tmp80);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block35, tmp77, tmp78, tmp79, tmp80);
    } else {
      ca_.Goto(&block36, tmp77, tmp78, tmp79, tmp80);
    }
  }

  if (block35.is_used()) {
    TNode<Number> tmp81;
    TNode<Number> tmp82;
    TNode<HeapNumber> tmp83;
    TNode<Float64T> tmp84;
    ca_.Bind(&block35, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<BoolT> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_kMode, kModeValueIsAnyNumber_0(state_))));
    ca_.Branch(tmp85, &block38, &block39, tmp81, tmp82, tmp83, tmp84);
  }

  if (block38.is_used()) {
    TNode<Number> tmp86;
    TNode<Number> tmp87;
    TNode<HeapNumber> tmp88;
    TNode<Float64T> tmp89;
    ca_.Bind(&block38, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<Float64T> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_float64_constexpr_float64_0(state_, kMaxSafeInteger);
    TNode<BoolT> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp89}, TNode<Float64T>{tmp90});
    ca_.Branch(tmp91, &block41, &block42, tmp86, tmp87, tmp88, tmp89);
  }

  if (block41.is_used()) {
    TNode<Number> tmp92;
    TNode<Number> tmp93;
    TNode<HeapNumber> tmp94;
    TNode<Float64T> tmp95;
    ca_.Bind(&block41, &tmp92, &tmp93, &tmp94, &tmp95);
    ca_.Goto(label_IfSafeIntegerOverflow);
  }

  if (block42.is_used()) {
    TNode<Number> tmp96;
    TNode<Number> tmp97;
    TNode<HeapNumber> tmp98;
    TNode<Float64T> tmp99;
    ca_.Bind(&block42, &tmp96, &tmp97, &tmp98, &tmp99);
    ca_.Goto(&block40, tmp96, tmp97, tmp98, tmp99);
  }

  if (block39.is_used()) {
    TNode<Number> tmp100;
    TNode<Number> tmp101;
    TNode<HeapNumber> tmp102;
    TNode<Float64T> tmp103;
    ca_.Bind(&block39, &tmp100, &tmp101, &tmp102, &tmp103);
    ca_.Goto(&block40, tmp100, tmp101, tmp102, tmp103);
  }

  if (block46.is_used()) {
    TNode<Number> tmp104;
    TNode<Number> tmp105;
    TNode<HeapNumber> tmp106;
    TNode<Float64T> tmp107;
    ca_.Bind(&block46, &tmp104, &tmp105, &tmp106, &tmp107);
    CodeStubAssembler(state_).FailAssert("Torque assert 'valueDouble <= kMaxSafeInteger' failed", "src/builtins/base.tq", 1161);
  }

  if (block45.is_used()) {
    TNode<Number> tmp108;
    TNode<Number> tmp109;
    TNode<HeapNumber> tmp110;
    TNode<Float64T> tmp111;
    ca_.Bind(&block45, &tmp108, &tmp109, &tmp110, &tmp111);
  }

  if (block40.is_used()) {
    TNode<Number> tmp112;
    TNode<Number> tmp113;
    TNode<HeapNumber> tmp114;
    TNode<Float64T> tmp115;
    ca_.Bind(&block40, &tmp112, &tmp113, &tmp114, &tmp115);
    ca_.Goto(&block37, tmp112, tmp113, tmp114, tmp115);
  }

  if (block36.is_used()) {
    TNode<Number> tmp116;
    TNode<Number> tmp117;
    TNode<HeapNumber> tmp118;
    TNode<Float64T> tmp119;
    ca_.Bind(&block36, &tmp116, &tmp117, &tmp118, &tmp119);
    TNode<BoolT> tmp120;
    USE(tmp120);
    tmp120 = FromConstexpr_bool_constexpr_bool_0(state_, ((CodeStubAssembler(state_).ConstexprInt31Equal(p_kMode, kModeValueIsAnyNumber_0(state_))) || (CodeStubAssembler(state_).ConstexprInt31Equal(p_kMode, kModeValueIsSafeInteger_0(state_)))));
    ca_.Branch(tmp120, &block47, &block48, tmp116, tmp117, tmp118, tmp119);
  }

  if (block47.is_used()) {
    TNode<Number> tmp121;
    TNode<Number> tmp122;
    TNode<HeapNumber> tmp123;
    TNode<Float64T> tmp124;
    ca_.Bind(&block47, &tmp121, &tmp122, &tmp123, &tmp124);
    TNode<Float64T> tmp125;
    USE(tmp125);
    tmp125 = FromConstexpr_float64_constexpr_float64_0(state_, kMaxUInt32Double);
    TNode<BoolT> tmp126;
    USE(tmp126);
    tmp126 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp124}, TNode<Float64T>{tmp125});
    ca_.Branch(tmp126, &block50, &block51, tmp121, tmp122, tmp123, tmp124);
  }

  if (block50.is_used()) {
    TNode<Number> tmp127;
    TNode<Number> tmp128;
    TNode<HeapNumber> tmp129;
    TNode<Float64T> tmp130;
    ca_.Bind(&block50, &tmp127, &tmp128, &tmp129, &tmp130);
    ca_.Goto(label_IfUIntPtrOverflow);
  }

  if (block51.is_used()) {
    TNode<Number> tmp131;
    TNode<Number> tmp132;
    TNode<HeapNumber> tmp133;
    TNode<Float64T> tmp134;
    ca_.Bind(&block51, &tmp131, &tmp132, &tmp133, &tmp134);
    ca_.Goto(&block49, tmp131, tmp132, tmp133, tmp134);
  }

  if (block48.is_used()) {
    TNode<Number> tmp135;
    TNode<Number> tmp136;
    TNode<HeapNumber> tmp137;
    TNode<Float64T> tmp138;
    ca_.Bind(&block48, &tmp135, &tmp136, &tmp137, &tmp138);
    ca_.Goto(&block49, tmp135, tmp136, tmp137, tmp138);
  }

  if (block55.is_used()) {
    TNode<Number> tmp139;
    TNode<Number> tmp140;
    TNode<HeapNumber> tmp141;
    TNode<Float64T> tmp142;
    ca_.Bind(&block55, &tmp139, &tmp140, &tmp141, &tmp142);
    CodeStubAssembler(state_).FailAssert("Torque assert 'valueDouble <= kMaxUInt32Double' failed", "src/builtins/base.tq", 1170);
  }

  if (block54.is_used()) {
    TNode<Number> tmp143;
    TNode<Number> tmp144;
    TNode<HeapNumber> tmp145;
    TNode<Float64T> tmp146;
    ca_.Bind(&block54, &tmp143, &tmp144, &tmp145, &tmp146);
  }

  if (block49.is_used()) {
    TNode<Number> tmp147;
    TNode<Number> tmp148;
    TNode<HeapNumber> tmp149;
    TNode<Float64T> tmp150;
    ca_.Bind(&block49, &tmp147, &tmp148, &tmp149, &tmp150);
    ca_.Goto(&block37, tmp147, tmp148, tmp149, tmp150);
  }

  if (block37.is_used()) {
    TNode<Number> tmp151;
    TNode<Number> tmp152;
    TNode<HeapNumber> tmp153;
    TNode<Float64T> tmp154;
    ca_.Bind(&block37, &tmp151, &tmp152, &tmp153, &tmp154);
    TNode<UintPtrT> tmp155;
    USE(tmp155);
    tmp155 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp154});
    ca_.Goto(&block4, tmp151, tmp155);
  }

  if (block4.is_used()) {
    TNode<Number> tmp156;
    TNode<UintPtrT> tmp157;
    ca_.Bind(&block4, &tmp156, &tmp157);
    ca_.Goto(&block56, tmp156, tmp157);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfLessThanZero);
  }

    TNode<Number> tmp158;
    TNode<UintPtrT> tmp159;
    ca_.Bind(&block56, &tmp158, &tmp159);
  return TNode<UintPtrT>{tmp159};
}

TNode<UintPtrT> ChangeUintPtrNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = TryNumberToUintPtr_0(state_, TNode<Number>{tmp0}, kModeValueIsSafeIntegerUintPtr_0(state_), &label0, &label1, &label2);
    ca_.Goto(&block4, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp0);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block7, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block5, &tmp2, &tmp3);
    ca_.Goto(&block3, tmp2);
  }

  if (block6.is_used()) {
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block6, &tmp4, &tmp5);
    ca_.Goto(&block3, tmp4);
  }

  if (block7.is_used()) {
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    ca_.Bind(&block7, &tmp6, &tmp7);
    ca_.Goto(&block3, tmp6);
  }

  if (block4.is_used()) {
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<UintPtrT> tmp10;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block8, tmp8, tmp10);
  }

  if (block3.is_used()) {
    TNode<Number> tmp11;
    ca_.Bind(&block3, &tmp11);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Number> tmp12;
    TNode<UintPtrT> tmp13;
    ca_.Bind(&block8, &tmp12, &tmp13);
  return TNode<UintPtrT>{tmp13};
}

TNode<UintPtrT> ChangeSafeIntegerNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_value, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = TryNumberToUintPtr_0(state_, TNode<Number>{tmp0}, kModeValueIsSafeInteger_0(state_), &label0, &label1, &label2);
    ca_.Goto(&block5, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp0);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block8, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block6, &tmp2, &tmp3);
    ca_.Goto(&block4, tmp2);
  }

  if (block7.is_used()) {
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block7, &tmp4, &tmp5);
    ca_.Goto(label_IfUIntPtrOverflow);
  }

  if (block8.is_used()) {
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    ca_.Bind(&block8, &tmp6, &tmp7);
    ca_.Goto(&block4, tmp6);
  }

  if (block5.is_used()) {
    TNode<Number> tmp8;
    TNode<Number> tmp9;
    TNode<UintPtrT> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block9, tmp8, tmp10);
  }

  if (block4.is_used()) {
    TNode<Number> tmp11;
    ca_.Bind(&block4, &tmp11);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Number> tmp12;
    TNode<UintPtrT> tmp13;
    ca_.Bind(&block9, &tmp12, &tmp13);
  return TNode<UintPtrT>{tmp13};
}

TNode<UintPtrT> ToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_IfLessThanZero, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow, compiler::CodeAssemblerLabel* label_IfSafeIntegerOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Undefined_0(state_);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block5, &block6, tmp0, tmp1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp4, &tmp5);
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp4, tmp5, tmp6);
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block6, &tmp7, &tmp8);
    TNode<Number> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp7}, TNode<Object>{tmp8}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp10 = TryNumberToUintPtr_0(state_, TNode<Number>{tmp9}, kModeValueIsAnyNumber_0(state_), &label0, &label1, &label2);
    ca_.Goto(&block7, tmp7, tmp8, tmp9, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp7, tmp8, tmp9, tmp9);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block9, tmp7, tmp8, tmp9, tmp9);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block10, tmp7, tmp8, tmp9, tmp9);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    ca_.Bind(&block8, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(label_IfLessThanZero);
  }

  if (block9.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Number> tmp17;
    TNode<Number> tmp18;
    ca_.Bind(&block9, &tmp15, &tmp16, &tmp17, &tmp18);
    ca_.Goto(label_IfUIntPtrOverflow);
  }

  if (block10.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<Number> tmp21;
    TNode<Number> tmp22;
    ca_.Bind(&block10, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(label_IfSafeIntegerOverflow);
  }

  if (block7.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Number> tmp25;
    TNode<Number> tmp26;
    TNode<UintPtrT> tmp27;
    ca_.Bind(&block7, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    ca_.Goto(&block4, tmp23, tmp24, tmp27);
  }

  if (block4.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<UintPtrT> tmp30;
    ca_.Bind(&block4, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block11, tmp28, tmp29, tmp30);
  }

    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<UintPtrT> tmp33;
    ca_.Bind(&block11, &tmp31, &tmp32, &tmp33);
  return TNode<UintPtrT>{tmp33};
}

TNode<UintPtrT> ToIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_IfRangeError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number, Number, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Undefined_0(state_);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block3, &tmp4, &tmp5);
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block2, tmp4, tmp5, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block4, &tmp7, &tmp8);
    TNode<Number> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp7}, TNode<Object>{tmp8}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp10 = TryNumberToUintPtr_0(state_, TNode<Number>{tmp9}, kModeValueIsAnyNumber_0(state_), &label0, &label1, &label2);
    ca_.Goto(&block5, tmp7, tmp8, tmp9, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp7, tmp8, tmp9, tmp9);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp7, tmp8, tmp9, tmp9);
    }
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block8, tmp7, tmp8, tmp9, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Number> tmp17;
    TNode<Number> tmp18;
    ca_.Bind(&block7, &tmp15, &tmp16, &tmp17, &tmp18);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<Number> tmp21;
    TNode<Number> tmp22;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Number> tmp25;
    TNode<Number> tmp26;
    TNode<UintPtrT> tmp27;
    ca_.Bind(&block5, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    ca_.Goto(&block2, tmp23, tmp24, tmp27);
  }

  if (block2.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<UintPtrT> tmp30;
    ca_.Bind(&block2, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block9, tmp28, tmp29, tmp30);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfRangeError);
  }

    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<UintPtrT> tmp33;
    ca_.Bind(&block9, &tmp31, &tmp32, &tmp33);
  return TNode<UintPtrT>{tmp33};
}

TNode<Number> GetLengthProperty_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSArgumentsObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSArgumentsObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block7, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<JSArgumentsObject> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = Cast_JSStrictArgumentsObject_1(state_, TNode<Context>{tmp3}, TNode<Object>{ca_.UncheckedCast<Object>(tmp5)}, &label0);
    ca_.Goto(&block10, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSArray> tmp14;
    ca_.Bind(&block6, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp15);
    TNode<Number>tmp16 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp14, tmp15});
    ca_.Goto(&block1, tmp9, tmp10, tmp16);
  }

  if (block11.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Context> tmp21;
    ca_.Bind(&block11, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<JSArgumentsObject> tmp22;
    USE(tmp22);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp22 = Cast_JSSloppyArgumentsObject_1(state_, TNode<Context>{tmp17}, TNode<Object>{ca_.UncheckedCast<Object>(tmp19)}, &label0);
    ca_.Goto(&block14, tmp17, tmp18, tmp19, ca_.UncheckedCast<Object>(tmp19), tmp17, tmp22);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp17, tmp18, tmp19, ca_.UncheckedCast<Object>(tmp19), tmp17);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Context> tmp27;
    TNode<JSArgumentsObject> tmp28;
    ca_.Bind(&block10, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<IntPtrT> tmp29 = ca_.IntPtrConstant(JSStrictArgumentsObject::kLengthOffset);
    USE(tmp29);
    TNode<Object>tmp30 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.Goto(&block3, tmp23, tmp24, tmp30);
  }

  if (block15.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    TNode<Context> tmp35;
    ca_.Bind(&block15, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<String> tmp36;
    USE(tmp36);
    tmp36 = kLengthString_0(state_);
    TNode<Object> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp31}, TNode<Object>{tmp32}, TNode<Object>{tmp36});
    ca_.Goto(&block3, tmp31, tmp32, tmp37);
  }

  if (block14.is_used()) {
    TNode<Context> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<Context> tmp42;
    TNode<JSArgumentsObject> tmp43;
    ca_.Bind(&block14, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<IntPtrT> tmp44 = ca_.IntPtrConstant(JSSloppyArgumentsObject::kLengthOffset);
    USE(tmp44);
    TNode<Object>tmp45 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp43, tmp44});
    ca_.Goto(&block3, tmp38, tmp39, tmp45);
  }

  if (block3.is_used()) {
    TNode<Context> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    ca_.Bind(&block3, &tmp46, &tmp47, &tmp48);
    TNode<Number> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp46}, TNode<Object>{tmp48});
    ca_.Goto(&block1, tmp46, tmp47, tmp49);
  }

  if (block1.is_used()) {
    TNode<Context> tmp50;
    TNode<Object> tmp51;
    TNode<Number> tmp52;
    ca_.Bind(&block1, &tmp50, &tmp51, &tmp52);
    ca_.Goto(&block16, tmp50, tmp51, tmp52);
  }

    TNode<Context> tmp53;
    TNode<Object> tmp54;
    TNode<Number> tmp55;
    ca_.Bind(&block16, &tmp53, &tmp54, &tmp55);
  return TNode<Number>{tmp55};
}

TNode<JSReceiver> GetMethod_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<Name> p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined, compiler::CodeAssemblerLabel* label_IfMethodNotCallable, compiler::TypedCodeAssemblerVariable<Object>* label_IfMethodNotCallable_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object, Object, Context> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, Object, Object, Context, JSReceiver> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Name, JSReceiver> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_name);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Name> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2});
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp3}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block6, &block7, tmp0, tmp1, tmp2, tmp3, tmp5);
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Name> tmp8;
    TNode<Object> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block8, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block7.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<Name> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block7, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = Null_0(state_);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp15}, TNode<HeapObject>{tmp17});
    ca_.Goto(&block8, tmp12, tmp13, tmp14, tmp15, tmp16, tmp18);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<Name> tmp21;
    TNode<Object> tmp22;
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Branch(tmp24, &block4, &block5, tmp19, tmp20, tmp21, tmp22);
  }

  if (block4.is_used()) {
    TNode<Context> tmp25;
    TNode<Object> tmp26;
    TNode<Name> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block4, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(label_IfNullOrUndefined);
  }

  if (block5.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<Name> tmp31;
    TNode<Object> tmp32;
    ca_.Bind(&block5, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<JSReceiver> tmp33;
    USE(tmp33);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp33 = Cast_Callable_1(state_, TNode<Context>{tmp29}, TNode<Object>{tmp32}, &label0);
    ca_.Goto(&block11, tmp29, tmp30, tmp31, tmp32, tmp32, tmp29, tmp33);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp29, tmp30, tmp31, tmp32, tmp32, tmp29);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<Name> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Context> tmp39;
    ca_.Bind(&block12, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    *label_IfMethodNotCallable_parameter_0 = tmp37;
    ca_.Goto(label_IfMethodNotCallable);
  }

  if (block11.is_used()) {
    TNode<Context> tmp40;
    TNode<Object> tmp41;
    TNode<Name> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    ca_.Bind(&block11, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    ca_.Goto(&block13, tmp40, tmp41, tmp42, tmp46);
  }

    TNode<Context> tmp47;
    TNode<Object> tmp48;
    TNode<Name> tmp49;
    TNode<JSReceiver> tmp50;
    ca_.Bind(&block13, &tmp47, &tmp48, &tmp49, &tmp50);
  return TNode<JSReceiver>{tmp50};
}

TNode<JSReceiver> GetMethod_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<String> p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, Object, String, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, Object, String, Context, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, Object, String, Context, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, JSReceiver> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_name);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp3 = GetMethod_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Name>{tmp2}, &label0, &label1, &result_1_0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp2, tmp1, tmp2, tmp0, result_1_0.value());
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<String> tmp6;
    TNode<Object> tmp7;
    TNode<String> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block6, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(label_IfNullOrUndefined);
  }

  if (block7.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<String> tmp12;
    TNode<Object> tmp13;
    TNode<String> tmp14;
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    ca_.Bind(&block7, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp10}, MessageTemplate::kPropertyNotFunction, TNode<Object>{tmp16}, TNode<Object>{tmp12}, TNode<Object>{tmp11});
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<String> tmp19;
    TNode<Object> tmp20;
    TNode<String> tmp21;
    TNode<Context> tmp22;
    TNode<JSReceiver> tmp23;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block8, tmp17, tmp18, tmp19, tmp23);
  }

    TNode<Context> tmp24;
    TNode<Object> tmp25;
    TNode<String> tmp26;
    TNode<JSReceiver> tmp27;
    ca_.Bind(&block8, &tmp24, &tmp25, &tmp26, &tmp27);
  return TNode<JSReceiver>{tmp27};
}

TNode<JSReceiver> GetMethod_2(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, const char* p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, String, Context, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).StringConstant(p_name);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = GetMethod_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<String> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(label_IfNullOrUndefined);
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<String> tmp12;
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block5, tmp9, tmp10, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
  return TNode<JSReceiver>{tmp17};
}

TNode<JSReceiver> GetMethod_3(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<Symbol> p_symbol, compiler::CodeAssemblerLabel* label_IfNullOrUndefined) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object, Object, Context> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, Object, Object, Context, JSReceiver> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Symbol, JSReceiver> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_symbol);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Symbol> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2});
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp3}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block5, &block6, tmp0, tmp1, tmp2, tmp3, tmp5);
  }

  if (block5.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Symbol> tmp8;
    TNode<Object> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block7, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<Symbol> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = Null_0(state_);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp15}, TNode<HeapObject>{tmp17});
    ca_.Goto(&block7, tmp12, tmp13, tmp14, tmp15, tmp16, tmp18);
  }

  if (block7.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<Symbol> tmp21;
    TNode<Object> tmp22;
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    ca_.Bind(&block7, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Branch(tmp24, &block3, &block4, tmp19, tmp20, tmp21, tmp22);
  }

  if (block3.is_used()) {
    TNode<Context> tmp25;
    TNode<Object> tmp26;
    TNode<Symbol> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block3, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(label_IfNullOrUndefined);
  }

  if (block4.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<Symbol> tmp31;
    TNode<Object> tmp32;
    ca_.Bind(&block4, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<JSReceiver> tmp33;
    USE(tmp33);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp33 = Cast_Callable_1(state_, TNode<Context>{tmp29}, TNode<Object>{tmp32}, &label0);
    ca_.Goto(&block10, tmp29, tmp30, tmp31, tmp32, tmp32, tmp29, tmp33);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp29, tmp30, tmp31, tmp32, tmp32, tmp29);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<Symbol> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Context> tmp39;
    ca_.Bind(&block11, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp34}, MessageTemplate::kPropertyNotFunction, TNode<Object>{tmp37}, TNode<Object>{tmp36}, TNode<Object>{tmp35});
  }

  if (block10.is_used()) {
    TNode<Context> tmp40;
    TNode<Object> tmp41;
    TNode<Symbol> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    ca_.Bind(&block10, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    ca_.Goto(&block12, tmp40, tmp41, tmp42, tmp46);
  }

    TNode<Context> tmp47;
    TNode<Object> tmp48;
    TNode<Symbol> tmp49;
    TNode<JSReceiver> tmp50;
    ca_.Bind(&block12, &tmp47, &tmp48, &tmp49, &tmp50);
  return TNode<JSReceiver>{tmp50};
}

TNode<UintPtrT> ConvertToRelativeIndex_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_index, TNode<UintPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_index, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<UintPtrT> tmp4;
    USE(tmp4);
    tmp4 = ConvertToRelativeIndex_2(state_, TNode<Number>{tmp3}, TNode<UintPtrT>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Object> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8);
  return TNode<UintPtrT>{tmp8};
}

TNode<UintPtrT> ConvertToRelativeIndex_2(compiler::CodeAssemblerState* state_, TNode<Number> p_indexNumber, TNode<UintPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, IntPtrT, UintPtrT, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T, Float64T> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T, Float64T> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T, Float64T, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T, Float64T> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, UintPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, UintPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_indexNumber, p_length);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<UintPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp0, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Number> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<Number> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Float64T> tmp7;
    USE(tmp7);
    tmp7 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp5)});
    TNode<Float64T> tmp8;
    USE(tmp8);
    tmp8 = Convert_float64_uintptr_0(state_, TNode<UintPtrT>{tmp4});
    TNode<Float64T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp7}, TNode<Float64T>{tmp9});
    ca_.Branch(tmp10, &block29, &block30, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapNumber>(tmp5), tmp7, tmp8);
  }

  if (block4.is_used()) {
    TNode<Number> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    TNode<Smi> tmp15;
    ca_.Bind(&block4, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp15});
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp17});
    ca_.Branch(tmp18, &block6, &block7, tmp11, tmp12, tmp13, tmp15, tmp16);
  }

  if (block6.is_used()) {
    TNode<Number> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<Number> tmp21;
    TNode<Smi> tmp22;
    TNode<IntPtrT> tmp23;
    ca_.Bind(&block6, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<UintPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp23});
    TNode<UintPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp24}, TNode<UintPtrT>{tmp20});
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp20});
    ca_.Branch(tmp26, &block9, &block10, tmp19, tmp20, tmp21, tmp22, tmp23, tmp25);
  }

  if (block9.is_used()) {
    TNode<Number> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<Number> tmp29;
    TNode<Smi> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    ca_.Bind(&block9, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block11, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp32);
  }

  if (block10.is_used()) {
    TNode<Number> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<Number> tmp35;
    TNode<Smi> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<UintPtrT> tmp38;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<UintPtrT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block11, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39);
  }

  if (block11.is_used()) {
    TNode<Number> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Number> tmp42;
    TNode<Smi> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<UintPtrT> tmp46;
    ca_.Bind(&block11, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    ca_.Goto(&block1, tmp40, tmp41, tmp46);
  }

  if (block7.is_used()) {
    TNode<Number> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Number> tmp49;
    TNode<Smi> tmp50;
    TNode<IntPtrT> tmp51;
    ca_.Bind(&block7, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<UintPtrT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp51});
    TNode<BoolT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp52}, TNode<UintPtrT>{tmp48});
    ca_.Branch(tmp53, &block13, &block14, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52);
  }

  if (block13.is_used()) {
    TNode<Number> tmp54;
    TNode<UintPtrT> tmp55;
    TNode<Number> tmp56;
    TNode<Smi> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<UintPtrT> tmp59;
    ca_.Bind(&block13, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    ca_.Goto(&block15, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp59);
  }

  if (block14.is_used()) {
    TNode<Number> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<Number> tmp62;
    TNode<Smi> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<UintPtrT> tmp65;
    ca_.Bind(&block14, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block15, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp61);
  }

  if (block15.is_used()) {
    TNode<Number> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<Number> tmp68;
    TNode<Smi> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<UintPtrT> tmp72;
    ca_.Bind(&block15, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    ca_.Goto(&block1, tmp66, tmp67, tmp72);
  }

  if (block20.is_used()) {
    TNode<Number> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<Number> tmp75;
    TNode<HeapNumber> tmp76;
    ca_.Bind(&block20, &tmp73, &tmp74, &tmp75, &tmp76);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(indexHeapNumber)' failed", "src/builtins/base.tq", 1314);
  }

  if (block19.is_used()) {
    TNode<Number> tmp77;
    TNode<UintPtrT> tmp78;
    TNode<Number> tmp79;
    TNode<HeapNumber> tmp80;
    ca_.Bind(&block19, &tmp77, &tmp78, &tmp79, &tmp80);
  }

  if (block24.is_used()) {
    TNode<Number> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<Number> tmp83;
    TNode<HeapNumber> tmp84;
    TNode<Float64T> tmp85;
    ca_.Bind(&block24, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Float64IsNaN(indexDouble)' failed", "src/builtins/base.tq", 1318);
  }

  if (block23.is_used()) {
    TNode<Number> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<Number> tmp88;
    TNode<HeapNumber> tmp89;
    TNode<Float64T> tmp90;
    ca_.Bind(&block23, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
  }

  if (block28.is_used()) {
    TNode<Number> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<Number> tmp93;
    TNode<HeapNumber> tmp94;
    TNode<Float64T> tmp95;
    TNode<Float64T> tmp96;
    ca_.Bind(&block28, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96);
    CodeStubAssembler(state_).FailAssert("Torque assert 'lengthDouble <= kMaxSafeInteger' failed", "src/builtins/base.tq", 1320);
  }

  if (block27.is_used()) {
    TNode<Number> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<Number> tmp99;
    TNode<HeapNumber> tmp100;
    TNode<Float64T> tmp101;
    TNode<Float64T> tmp102;
    ca_.Bind(&block27, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
  }

  if (block29.is_used()) {
    TNode<Number> tmp103;
    TNode<UintPtrT> tmp104;
    TNode<Number> tmp105;
    TNode<HeapNumber> tmp106;
    TNode<Float64T> tmp107;
    TNode<Float64T> tmp108;
    ca_.Bind(&block29, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<Float64T> tmp109;
    USE(tmp109);
    tmp109 = CodeStubAssembler(state_).Float64Add(TNode<Float64T>{tmp108}, TNode<Float64T>{tmp107});
    TNode<Float64T> tmp110;
    USE(tmp110);
    tmp110 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp111;
    USE(tmp111);
    tmp111 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp109}, TNode<Float64T>{tmp110});
    ca_.Branch(tmp111, &block32, &block33, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109);
  }

  if (block32.is_used()) {
    TNode<Number> tmp112;
    TNode<UintPtrT> tmp113;
    TNode<Number> tmp114;
    TNode<HeapNumber> tmp115;
    TNode<Float64T> tmp116;
    TNode<Float64T> tmp117;
    TNode<Float64T> tmp118;
    ca_.Bind(&block32, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    TNode<UintPtrT> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp118});
    ca_.Goto(&block34, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119);
  }

  if (block33.is_used()) {
    TNode<Number> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<Number> tmp122;
    TNode<HeapNumber> tmp123;
    TNode<Float64T> tmp124;
    TNode<Float64T> tmp125;
    TNode<Float64T> tmp126;
    ca_.Bind(&block33, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126);
    TNode<UintPtrT> tmp127;
    USE(tmp127);
    tmp127 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block34, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127);
  }

  if (block34.is_used()) {
    TNode<Number> tmp128;
    TNode<UintPtrT> tmp129;
    TNode<Number> tmp130;
    TNode<HeapNumber> tmp131;
    TNode<Float64T> tmp132;
    TNode<Float64T> tmp133;
    TNode<Float64T> tmp134;
    TNode<UintPtrT> tmp135;
    ca_.Bind(&block34, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    ca_.Goto(&block1, tmp128, tmp129, tmp135);
  }

  if (block30.is_used()) {
    TNode<Number> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<Number> tmp138;
    TNode<HeapNumber> tmp139;
    TNode<Float64T> tmp140;
    TNode<Float64T> tmp141;
    ca_.Bind(&block30, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141);
    TNode<BoolT> tmp142;
    USE(tmp142);
    tmp142 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp140}, TNode<Float64T>{tmp141});
    ca_.Branch(tmp142, &block36, &block37, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141);
  }

  if (block36.is_used()) {
    TNode<Number> tmp143;
    TNode<UintPtrT> tmp144;
    TNode<Number> tmp145;
    TNode<HeapNumber> tmp146;
    TNode<Float64T> tmp147;
    TNode<Float64T> tmp148;
    ca_.Bind(&block36, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    ca_.Goto(&block38, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp147);
  }

  if (block37.is_used()) {
    TNode<Number> tmp149;
    TNode<UintPtrT> tmp150;
    TNode<Number> tmp151;
    TNode<HeapNumber> tmp152;
    TNode<Float64T> tmp153;
    TNode<Float64T> tmp154;
    ca_.Bind(&block37, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154);
    ca_.Goto(&block38, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp154);
  }

  if (block38.is_used()) {
    TNode<Number> tmp155;
    TNode<UintPtrT> tmp156;
    TNode<Number> tmp157;
    TNode<HeapNumber> tmp158;
    TNode<Float64T> tmp159;
    TNode<Float64T> tmp160;
    TNode<Float64T> tmp161;
    ca_.Bind(&block38, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    TNode<UintPtrT> tmp162;
    USE(tmp162);
    tmp162 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp161});
    ca_.Goto(&block1, tmp155, tmp156, tmp162);
  }

  if (block1.is_used()) {
    TNode<Number> tmp163;
    TNode<UintPtrT> tmp164;
    TNode<UintPtrT> tmp165;
    ca_.Bind(&block1, &tmp163, &tmp164, &tmp165);
    ca_.Goto(&block40, tmp163, tmp164, tmp165);
  }

    TNode<Number> tmp166;
    TNode<UintPtrT> tmp167;
    TNode<UintPtrT> tmp168;
    ca_.Bind(&block40, &tmp166, &tmp167, &tmp168);
  return TNode<UintPtrT>{tmp168};
}

TNode<UintPtrT> ClampToIndexRange_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_index, TNode<UintPtrT> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, UintPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_index, p_limit);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<UintPtrT> tmp4;
    USE(tmp4);
    tmp4 = ClampToIndexRange_1(state_, TNode<Number>{tmp3}, TNode<UintPtrT>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp4);
  }

    TNode<Context> tmp5;
    TNode<Object> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8);
  return TNode<UintPtrT>{tmp8};
}

TNode<UintPtrT> ClampToIndexRange_1(compiler::CodeAssemblerState* state_, TNode<Number> p_indexNumber, TNode<UintPtrT> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, Smi, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, Number, HeapNumber, Float64T, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, UintPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT, UintPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_indexNumber, p_limit);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<UintPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp0, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Number> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<Number> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Float64T> tmp7;
    USE(tmp7);
    tmp7 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp5)});
    TNode<Float64T> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Float64LessThanOrEqual(TNode<Float64T>{tmp7}, TNode<Float64T>{tmp8});
    ca_.Branch(tmp9, &block18, &block19, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapNumber>(tmp5), tmp7);
  }

  if (block4.is_used()) {
    TNode<Number> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp14}, TNode<Smi>{tmp15});
    ca_.Branch(tmp16, &block6, &block7, tmp10, tmp11, tmp12, tmp14);
  }

  if (block6.is_used()) {
    TNode<Number> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<Number> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block1, tmp17, tmp18, tmp21);
  }

  if (block7.is_used()) {
    TNode<Number> tmp22;
    TNode<UintPtrT> tmp23;
    TNode<Number> tmp24;
    TNode<Smi> tmp25;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp25});
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp26});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp27}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp28, &block8, &block9, tmp22, tmp23, tmp24, tmp25, tmp27);
  }

  if (block8.is_used()) {
    TNode<Number> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<Number> tmp31;
    TNode<Smi> tmp32;
    TNode<UintPtrT> tmp33;
    ca_.Bind(&block8, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block1, tmp29, tmp30, tmp30);
  }

  if (block9.is_used()) {
    TNode<Number> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<Number> tmp36;
    TNode<Smi> tmp37;
    TNode<UintPtrT> tmp38;
    ca_.Bind(&block9, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    ca_.Goto(&block1, tmp34, tmp35, tmp38);
  }

  if (block13.is_used()) {
    TNode<Number> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<Number> tmp41;
    TNode<HeapNumber> tmp42;
    ca_.Bind(&block13, &tmp39, &tmp40, &tmp41, &tmp42);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(indexHeapNumber)' failed", "src/builtins/base.tq", 1355);
  }

  if (block12.is_used()) {
    TNode<Number> tmp43;
    TNode<UintPtrT> tmp44;
    TNode<Number> tmp45;
    TNode<HeapNumber> tmp46;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46);
  }

  if (block17.is_used()) {
    TNode<Number> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Number> tmp49;
    TNode<HeapNumber> tmp50;
    TNode<Float64T> tmp51;
    ca_.Bind(&block17, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Float64IsNaN(indexDouble)' failed", "src/builtins/base.tq", 1359);
  }

  if (block16.is_used()) {
    TNode<Number> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<Number> tmp54;
    TNode<HeapNumber> tmp55;
    TNode<Float64T> tmp56;
    ca_.Bind(&block16, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
  }

  if (block18.is_used()) {
    TNode<Number> tmp57;
    TNode<UintPtrT> tmp58;
    TNode<Number> tmp59;
    TNode<HeapNumber> tmp60;
    TNode<Float64T> tmp61;
    ca_.Bind(&block18, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<UintPtrT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block1, tmp57, tmp58, tmp62);
  }

  if (block19.is_used()) {
    TNode<Number> tmp63;
    TNode<UintPtrT> tmp64;
    TNode<Number> tmp65;
    TNode<HeapNumber> tmp66;
    TNode<Float64T> tmp67;
    ca_.Bind(&block19, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Float64T> tmp68;
    USE(tmp68);
    tmp68 = Convert_float64_uintptr_0(state_, TNode<UintPtrT>{tmp64});
    TNode<BoolT> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).Float64GreaterThanOrEqual(TNode<Float64T>{tmp67}, TNode<Float64T>{tmp68});
    ca_.Branch(tmp69, &block24, &block25, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block23.is_used()) {
    TNode<Number> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<Number> tmp72;
    TNode<HeapNumber> tmp73;
    TNode<Float64T> tmp74;
    TNode<Float64T> tmp75;
    ca_.Bind(&block23, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    CodeStubAssembler(state_).FailAssert("Torque assert 'maxIndexDouble <= kMaxSafeInteger' failed", "src/builtins/base.tq", 1363);
  }

  if (block22.is_used()) {
    TNode<Number> tmp76;
    TNode<UintPtrT> tmp77;
    TNode<Number> tmp78;
    TNode<HeapNumber> tmp79;
    TNode<Float64T> tmp80;
    TNode<Float64T> tmp81;
    ca_.Bind(&block22, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
  }

  if (block24.is_used()) {
    TNode<Number> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<Number> tmp84;
    TNode<HeapNumber> tmp85;
    TNode<Float64T> tmp86;
    TNode<Float64T> tmp87;
    ca_.Bind(&block24, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
    ca_.Goto(&block1, tmp82, tmp83, tmp83);
  }

  if (block25.is_used()) {
    TNode<Number> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<Number> tmp90;
    TNode<HeapNumber> tmp91;
    TNode<Float64T> tmp92;
    TNode<Float64T> tmp93;
    ca_.Bind(&block25, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<UintPtrT> tmp94;
    USE(tmp94);
    tmp94 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp92});
    ca_.Goto(&block1, tmp88, tmp89, tmp94);
  }

  if (block1.is_used()) {
    TNode<Number> tmp95;
    TNode<UintPtrT> tmp96;
    TNode<UintPtrT> tmp97;
    ca_.Bind(&block1, &tmp95, &tmp96, &tmp97);
    ca_.Goto(&block26, tmp95, tmp96, tmp97);
  }

    TNode<Number> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    ca_.Bind(&block26, &tmp98, &tmp99, &tmp100);
  return TNode<UintPtrT>{tmp100};
}

TNode<BoolT> IsFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_context);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Object> tmp3;
    TNode<Context> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp5);
  }

  if (block3.is_used()) {
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block3, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = Is_FastJSArray_Object_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp6});
    ca_.Goto(&block1, tmp6, tmp7, tmp8);
  }

  if (block1.is_used()) {
    TNode<Object> tmp9;
    TNode<Context> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block1, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block4, tmp9, tmp10, tmp11);
  }

    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14);
  return TNode<BoolT>{tmp14};
}

void BranchIfFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_context);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsFastJSArray_0(state_, TNode<Object>{tmp0}, TNode<Context>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    TNode<Context> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(label_True);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    ca_.Goto(label_False);
  }
}

void BranchIfFastJSArrayForRead_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_context);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    TNode<Context> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    TNode<Context> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block2);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = Is_FastJSArrayForRead_Object_0(state_, TNode<Context>{tmp6}, TNode<Object>{tmp5});
    ca_.Branch(tmp7, &block5, &block6, tmp5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Object> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
    ca_.Goto(label_True);
  }

  if (block6.is_used()) {
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp10, &tmp11);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(label_False);
  }
}

TNode<BoolT> IsFastJSArrayWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Is_FastJSArrayWithNoCustomIteration_Object_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<BoolT> IsFastJSArrayForReadWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Is_FastJSArrayForReadWithNoCustomIteration_Object_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TF_BUILTIN(FastCreateDataProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSReceiver> parameter1 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSReceiver, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSReceiver, Context, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Object, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Object, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi, JSArray, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi, JSArray, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi, FixedArrayBase> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi, FixedArrayBase, FixedArray> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Object, Number> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number, JSArray, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number, JSArray, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number, FixedArrayBase> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number, FixedArrayBase, FixedDoubleArray> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, Number> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, JSArray, Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, JSArray, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, FixedArrayBase> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T, FixedArrayBase, FixedArray> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object, JSArray, Smi, BoolT, Int32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSArray> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_FastJSArray_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<JSReceiver> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block2, tmp5, tmp6, tmp7, tmp8);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Context> tmp16;
    TNode<JSArray> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp18 = Cast_Smi_0(state_, TNode<Object>{tmp13}, &label0);
    ca_.Goto(&block7, tmp11, tmp12, tmp13, tmp14, tmp17, tmp13, tmp18);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp11, tmp12, tmp13, tmp14, tmp17, tmp13);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<JSArray> tmp23;
    TNode<Object> tmp24;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Goto(&block2, tmp19, tmp20, tmp21, tmp22);
  }

  if (block7.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<JSArray> tmp29;
    TNode<Object> tmp30;
    TNode<Smi> tmp31;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<Smi> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp31}, TNode<Smi>{tmp32});
    ca_.Branch(tmp33, &block11, &block12, tmp25, tmp26, tmp27, tmp28, tmp29, tmp31, tmp33);
  }

  if (block11.is_used()) {
    TNode<Context> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<JSArray> tmp38;
    TNode<Smi> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block11, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block13, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block12.is_used()) {
    TNode<Context> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<JSArray> tmp46;
    TNode<Smi> tmp47;
    TNode<BoolT> tmp48;
    ca_.Bind(&block12, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<Smi> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp46});
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp47}, TNode<Smi>{tmp49});
    ca_.Goto(&block13, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp50);
  }

  if (block13.is_used()) {
    TNode<Context> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<JSArray> tmp55;
    TNode<Smi> tmp56;
    TNode<BoolT> tmp57;
    TNode<BoolT> tmp58;
    ca_.Bind(&block13, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    ca_.Branch(tmp58, &block9, &block10, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56);
  }

  if (block9.is_used()) {
    TNode<Context> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<JSArray> tmp63;
    TNode<Smi> tmp64;
    ca_.Bind(&block9, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Goto(&block2, tmp59, tmp60, tmp61, tmp62);
  }

  if (block10.is_used()) {
    TNode<Context> tmp65;
    TNode<JSReceiver> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<JSArray> tmp69;
    TNode<Smi> tmp70;
    ca_.Bind(&block10, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    EnsureWriteableFastElements_0(state_, TNode<Context>{tmp65}, TNode<JSArray>{tmp69});
    TNode<Smi> tmp71;
    USE(tmp71);
    tmp71 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp69});
    TNode<BoolT> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp70}, TNode<Smi>{tmp71});
    TNode<IntPtrT> tmp73 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp73);
    TNode<Map>tmp74 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp69, tmp73});
    TNode<Int32T> tmp75;
    USE(tmp75);
    tmp75 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp74});
    TNode<BoolT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).IsFastSmiElementsKind(TNode<Int32T>{tmp75});
    ca_.Branch(tmp76, &block14, &block15, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72, tmp75);
  }

  if (block14.is_used()) {
    TNode<Context> tmp77;
    TNode<JSReceiver> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<JSArray> tmp81;
    TNode<Smi> tmp82;
    TNode<BoolT> tmp83;
    TNode<Int32T> tmp84;
    ca_.Bind(&block14, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<Smi> tmp85;
    USE(tmp85);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp85 = Cast_Smi_0(state_, TNode<Object>{tmp80}, &label0);
    ca_.Goto(&block17, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp80, tmp85);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp80);
    }
  }

  if (block18.is_used()) {
    TNode<Context> tmp86;
    TNode<JSReceiver> tmp87;
    TNode<Object> tmp88;
    TNode<Object> tmp89;
    TNode<JSArray> tmp90;
    TNode<Smi> tmp91;
    TNode<BoolT> tmp92;
    TNode<Int32T> tmp93;
    TNode<Object> tmp94;
    ca_.Bind(&block18, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    ca_.Goto(&block2, tmp86, tmp87, tmp88, tmp89);
  }

  if (block17.is_used()) {
    TNode<Context> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<Object> tmp97;
    TNode<Object> tmp98;
    TNode<JSArray> tmp99;
    TNode<Smi> tmp100;
    TNode<BoolT> tmp101;
    TNode<Int32T> tmp102;
    TNode<Object> tmp103;
    TNode<Smi> tmp104;
    ca_.Bind(&block17, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    ca_.Branch(tmp101, &block19, &block20, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp104);
  }

  if (block19.is_used()) {
    TNode<Context> tmp105;
    TNode<JSReceiver> tmp106;
    TNode<Object> tmp107;
    TNode<Object> tmp108;
    TNode<JSArray> tmp109;
    TNode<Smi> tmp110;
    TNode<BoolT> tmp111;
    TNode<Int32T> tmp112;
    TNode<Smi> tmp113;
    ca_.Bind(&block19, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    compiler::CodeAssemblerLabel label0(&ca_);
    CodeStubAssembler(state_).BuildAppendJSArray(HOLEY_SMI_ELEMENTS, TNode<JSArray>{tmp109}, TNode<Object>{tmp108}, &label0);
    ca_.Goto(&block22, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp109, tmp108);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block23, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp109, tmp108);
    }
  }

  if (block23.is_used()) {
    TNode<Context> tmp114;
    TNode<JSReceiver> tmp115;
    TNode<Object> tmp116;
    TNode<Object> tmp117;
    TNode<JSArray> tmp118;
    TNode<Smi> tmp119;
    TNode<BoolT> tmp120;
    TNode<Int32T> tmp121;
    TNode<Smi> tmp122;
    TNode<JSArray> tmp123;
    TNode<Object> tmp124;
    ca_.Bind(&block23, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124);
    ca_.Goto(&block2, tmp114, tmp115, tmp116, tmp117);
  }

  if (block22.is_used()) {
    TNode<Context> tmp125;
    TNode<JSReceiver> tmp126;
    TNode<Object> tmp127;
    TNode<Object> tmp128;
    TNode<JSArray> tmp129;
    TNode<Smi> tmp130;
    TNode<BoolT> tmp131;
    TNode<Int32T> tmp132;
    TNode<Smi> tmp133;
    TNode<JSArray> tmp134;
    TNode<Object> tmp135;
    ca_.Bind(&block22, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    ca_.Goto(&block21, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133);
  }

  if (block20.is_used()) {
    TNode<Context> tmp136;
    TNode<JSReceiver> tmp137;
    TNode<Object> tmp138;
    TNode<Object> tmp139;
    TNode<JSArray> tmp140;
    TNode<Smi> tmp141;
    TNode<BoolT> tmp142;
    TNode<Int32T> tmp143;
    TNode<Smi> tmp144;
    ca_.Bind(&block20, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144);
    TNode<IntPtrT> tmp145 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp145);
    TNode<FixedArrayBase>tmp146 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp140, tmp145});
    TNode<FixedArray> tmp147;
    USE(tmp147);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp147 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp146}, &label0);
    ca_.Goto(&block26, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp146, tmp147);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block27, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp146);
    }
  }

  if (block27.is_used()) {
    TNode<Context> tmp148;
    TNode<JSReceiver> tmp149;
    TNode<Object> tmp150;
    TNode<Object> tmp151;
    TNode<JSArray> tmp152;
    TNode<Smi> tmp153;
    TNode<BoolT> tmp154;
    TNode<Int32T> tmp155;
    TNode<Smi> tmp156;
    TNode<FixedArrayBase> tmp157;
    ca_.Bind(&block27, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block26.is_used()) {
    TNode<Context> tmp158;
    TNode<JSReceiver> tmp159;
    TNode<Object> tmp160;
    TNode<Object> tmp161;
    TNode<JSArray> tmp162;
    TNode<Smi> tmp163;
    TNode<BoolT> tmp164;
    TNode<Int32T> tmp165;
    TNode<Smi> tmp166;
    TNode<FixedArrayBase> tmp167;
    TNode<FixedArray> tmp168;
    ca_.Bind(&block26, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp168}, TNode<Smi>{tmp163}, TNode<Object>{tmp166});
    ca_.Goto(&block21, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166);
  }

  if (block21.is_used()) {
    TNode<Context> tmp169;
    TNode<JSReceiver> tmp170;
    TNode<Object> tmp171;
    TNode<Object> tmp172;
    TNode<JSArray> tmp173;
    TNode<Smi> tmp174;
    TNode<BoolT> tmp175;
    TNode<Int32T> tmp176;
    TNode<Smi> tmp177;
    ca_.Bind(&block21, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177);
    ca_.Goto(&block16, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
  }

  if (block15.is_used()) {
    TNode<Context> tmp178;
    TNode<JSReceiver> tmp179;
    TNode<Object> tmp180;
    TNode<Object> tmp181;
    TNode<JSArray> tmp182;
    TNode<Smi> tmp183;
    TNode<BoolT> tmp184;
    TNode<Int32T> tmp185;
    ca_.Bind(&block15, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185);
    TNode<BoolT> tmp186;
    USE(tmp186);
    tmp186 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{tmp185});
    ca_.Branch(tmp186, &block28, &block29, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185);
  }

  if (block28.is_used()) {
    TNode<Context> tmp187;
    TNode<JSReceiver> tmp188;
    TNode<Object> tmp189;
    TNode<Object> tmp190;
    TNode<JSArray> tmp191;
    TNode<Smi> tmp192;
    TNode<BoolT> tmp193;
    TNode<Int32T> tmp194;
    ca_.Bind(&block28, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194);
    TNode<Number> tmp195;
    USE(tmp195);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp195 = Cast_Number_0(state_, TNode<Object>{tmp190}, &label0);
    ca_.Goto(&block31, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp190, tmp195);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block32, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp190);
    }
  }

  if (block32.is_used()) {
    TNode<Context> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<Object> tmp198;
    TNode<Object> tmp199;
    TNode<JSArray> tmp200;
    TNode<Smi> tmp201;
    TNode<BoolT> tmp202;
    TNode<Int32T> tmp203;
    TNode<Object> tmp204;
    ca_.Bind(&block32, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204);
    ca_.Goto(&block2, tmp196, tmp197, tmp198, tmp199);
  }

  if (block31.is_used()) {
    TNode<Context> tmp205;
    TNode<JSReceiver> tmp206;
    TNode<Object> tmp207;
    TNode<Object> tmp208;
    TNode<JSArray> tmp209;
    TNode<Smi> tmp210;
    TNode<BoolT> tmp211;
    TNode<Int32T> tmp212;
    TNode<Object> tmp213;
    TNode<Number> tmp214;
    ca_.Bind(&block31, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214);
    ca_.Branch(tmp211, &block33, &block34, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp214);
  }

  if (block33.is_used()) {
    TNode<Context> tmp215;
    TNode<JSReceiver> tmp216;
    TNode<Object> tmp217;
    TNode<Object> tmp218;
    TNode<JSArray> tmp219;
    TNode<Smi> tmp220;
    TNode<BoolT> tmp221;
    TNode<Int32T> tmp222;
    TNode<Number> tmp223;
    ca_.Bind(&block33, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223);
    compiler::CodeAssemblerLabel label0(&ca_);
    CodeStubAssembler(state_).BuildAppendJSArray(HOLEY_DOUBLE_ELEMENTS, TNode<JSArray>{tmp219}, TNode<Object>{tmp218}, &label0);
    ca_.Goto(&block36, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp219, tmp218);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block37, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp219, tmp218);
    }
  }

  if (block37.is_used()) {
    TNode<Context> tmp224;
    TNode<JSReceiver> tmp225;
    TNode<Object> tmp226;
    TNode<Object> tmp227;
    TNode<JSArray> tmp228;
    TNode<Smi> tmp229;
    TNode<BoolT> tmp230;
    TNode<Int32T> tmp231;
    TNode<Number> tmp232;
    TNode<JSArray> tmp233;
    TNode<Object> tmp234;
    ca_.Bind(&block37, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234);
    ca_.Goto(&block2, tmp224, tmp225, tmp226, tmp227);
  }

  if (block36.is_used()) {
    TNode<Context> tmp235;
    TNode<JSReceiver> tmp236;
    TNode<Object> tmp237;
    TNode<Object> tmp238;
    TNode<JSArray> tmp239;
    TNode<Smi> tmp240;
    TNode<BoolT> tmp241;
    TNode<Int32T> tmp242;
    TNode<Number> tmp243;
    TNode<JSArray> tmp244;
    TNode<Object> tmp245;
    ca_.Bind(&block36, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245);
    ca_.Goto(&block35, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243);
  }

  if (block34.is_used()) {
    TNode<Context> tmp246;
    TNode<JSReceiver> tmp247;
    TNode<Object> tmp248;
    TNode<Object> tmp249;
    TNode<JSArray> tmp250;
    TNode<Smi> tmp251;
    TNode<BoolT> tmp252;
    TNode<Int32T> tmp253;
    TNode<Number> tmp254;
    ca_.Bind(&block34, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254);
    TNode<IntPtrT> tmp255 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp255);
    TNode<FixedArrayBase>tmp256 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp250, tmp255});
    TNode<FixedDoubleArray> tmp257;
    USE(tmp257);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp257 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp256}, &label0);
    ca_.Goto(&block40, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251, tmp252, tmp253, tmp254, tmp256, tmp257);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block41, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251, tmp252, tmp253, tmp254, tmp256);
    }
  }

  if (block41.is_used()) {
    TNode<Context> tmp258;
    TNode<JSReceiver> tmp259;
    TNode<Object> tmp260;
    TNode<Object> tmp261;
    TNode<JSArray> tmp262;
    TNode<Smi> tmp263;
    TNode<BoolT> tmp264;
    TNode<Int32T> tmp265;
    TNode<Number> tmp266;
    TNode<FixedArrayBase> tmp267;
    ca_.Bind(&block41, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block40.is_used()) {
    TNode<Context> tmp268;
    TNode<JSReceiver> tmp269;
    TNode<Object> tmp270;
    TNode<Object> tmp271;
    TNode<JSArray> tmp272;
    TNode<Smi> tmp273;
    TNode<BoolT> tmp274;
    TNode<Int32T> tmp275;
    TNode<Number> tmp276;
    TNode<FixedArrayBase> tmp277;
    TNode<FixedDoubleArray> tmp278;
    ca_.Bind(&block40, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278);
    StoreFixedDoubleArrayDirect_0(state_, TNode<FixedDoubleArray>{tmp278}, TNode<Smi>{tmp273}, TNode<Number>{tmp276});
    ca_.Goto(&block35, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276);
  }

  if (block35.is_used()) {
    TNode<Context> tmp279;
    TNode<JSReceiver> tmp280;
    TNode<Object> tmp281;
    TNode<Object> tmp282;
    TNode<JSArray> tmp283;
    TNode<Smi> tmp284;
    TNode<BoolT> tmp285;
    TNode<Int32T> tmp286;
    TNode<Number> tmp287;
    ca_.Bind(&block35, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287);
    ca_.Goto(&block30, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286);
  }

  if (block29.is_used()) {
    TNode<Context> tmp288;
    TNode<JSReceiver> tmp289;
    TNode<Object> tmp290;
    TNode<Object> tmp291;
    TNode<JSArray> tmp292;
    TNode<Smi> tmp293;
    TNode<BoolT> tmp294;
    TNode<Int32T> tmp295;
    ca_.Bind(&block29, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295);
    ca_.Branch(tmp294, &block46, &block47, tmp288, tmp289, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295);
  }

  if (block45.is_used()) {
    TNode<Context> tmp296;
    TNode<JSReceiver> tmp297;
    TNode<Object> tmp298;
    TNode<Object> tmp299;
    TNode<JSArray> tmp300;
    TNode<Smi> tmp301;
    TNode<BoolT> tmp302;
    TNode<Int32T> tmp303;
    ca_.Bind(&block45, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastSmiOrTaggedElementsKind(kind)' failed", "src/builtins/base.tq", 1462);
  }

  if (block44.is_used()) {
    TNode<Context> tmp304;
    TNode<JSReceiver> tmp305;
    TNode<Object> tmp306;
    TNode<Object> tmp307;
    TNode<JSArray> tmp308;
    TNode<Smi> tmp309;
    TNode<BoolT> tmp310;
    TNode<Int32T> tmp311;
    ca_.Bind(&block44, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311);
  }

  if (block46.is_used()) {
    TNode<Context> tmp312;
    TNode<JSReceiver> tmp313;
    TNode<Object> tmp314;
    TNode<Object> tmp315;
    TNode<JSArray> tmp316;
    TNode<Smi> tmp317;
    TNode<BoolT> tmp318;
    TNode<Int32T> tmp319;
    ca_.Bind(&block46, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319);
    compiler::CodeAssemblerLabel label0(&ca_);
    CodeStubAssembler(state_).BuildAppendJSArray(HOLEY_ELEMENTS, TNode<JSArray>{tmp316}, TNode<Object>{tmp315}, &label0);
    ca_.Goto(&block49, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp316, tmp315);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block50, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318, tmp319, tmp316, tmp315);
    }
  }

  if (block50.is_used()) {
    TNode<Context> tmp320;
    TNode<JSReceiver> tmp321;
    TNode<Object> tmp322;
    TNode<Object> tmp323;
    TNode<JSArray> tmp324;
    TNode<Smi> tmp325;
    TNode<BoolT> tmp326;
    TNode<Int32T> tmp327;
    TNode<JSArray> tmp328;
    TNode<Object> tmp329;
    ca_.Bind(&block50, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329);
    ca_.Goto(&block2, tmp320, tmp321, tmp322, tmp323);
  }

  if (block49.is_used()) {
    TNode<Context> tmp330;
    TNode<JSReceiver> tmp331;
    TNode<Object> tmp332;
    TNode<Object> tmp333;
    TNode<JSArray> tmp334;
    TNode<Smi> tmp335;
    TNode<BoolT> tmp336;
    TNode<Int32T> tmp337;
    TNode<JSArray> tmp338;
    TNode<Object> tmp339;
    ca_.Bind(&block49, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339);
    ca_.Goto(&block48, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337);
  }

  if (block47.is_used()) {
    TNode<Context> tmp340;
    TNode<JSReceiver> tmp341;
    TNode<Object> tmp342;
    TNode<Object> tmp343;
    TNode<JSArray> tmp344;
    TNode<Smi> tmp345;
    TNode<BoolT> tmp346;
    TNode<Int32T> tmp347;
    ca_.Bind(&block47, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347);
    TNode<IntPtrT> tmp348 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp348);
    TNode<FixedArrayBase>tmp349 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp344, tmp348});
    TNode<FixedArray> tmp350;
    USE(tmp350);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp350 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp349}, &label0);
    ca_.Goto(&block53, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp349, tmp350);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block54, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp349);
    }
  }

  if (block54.is_used()) {
    TNode<Context> tmp351;
    TNode<JSReceiver> tmp352;
    TNode<Object> tmp353;
    TNode<Object> tmp354;
    TNode<JSArray> tmp355;
    TNode<Smi> tmp356;
    TNode<BoolT> tmp357;
    TNode<Int32T> tmp358;
    TNode<FixedArrayBase> tmp359;
    ca_.Bind(&block54, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block53.is_used()) {
    TNode<Context> tmp360;
    TNode<JSReceiver> tmp361;
    TNode<Object> tmp362;
    TNode<Object> tmp363;
    TNode<JSArray> tmp364;
    TNode<Smi> tmp365;
    TNode<BoolT> tmp366;
    TNode<Int32T> tmp367;
    TNode<FixedArrayBase> tmp368;
    TNode<FixedArray> tmp369;
    ca_.Bind(&block53, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369);
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp369}, TNode<Smi>{tmp365}, TNode<Object>{tmp363});
    ca_.Goto(&block48, tmp360, tmp361, tmp362, tmp363, tmp364, tmp365, tmp366, tmp367);
  }

  if (block48.is_used()) {
    TNode<Context> tmp370;
    TNode<JSReceiver> tmp371;
    TNode<Object> tmp372;
    TNode<Object> tmp373;
    TNode<JSArray> tmp374;
    TNode<Smi> tmp375;
    TNode<BoolT> tmp376;
    TNode<Int32T> tmp377;
    ca_.Bind(&block48, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377);
    ca_.Goto(&block30, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp377);
  }

  if (block30.is_used()) {
    TNode<Context> tmp378;
    TNode<JSReceiver> tmp379;
    TNode<Object> tmp380;
    TNode<Object> tmp381;
    TNode<JSArray> tmp382;
    TNode<Smi> tmp383;
    TNode<BoolT> tmp384;
    TNode<Int32T> tmp385;
    ca_.Bind(&block30, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385);
    ca_.Goto(&block16, tmp378, tmp379, tmp380, tmp381, tmp382, tmp383, tmp384, tmp385);
  }

  if (block16.is_used()) {
    TNode<Context> tmp386;
    TNode<JSReceiver> tmp387;
    TNode<Object> tmp388;
    TNode<Object> tmp389;
    TNode<JSArray> tmp390;
    TNode<Smi> tmp391;
    TNode<BoolT> tmp392;
    TNode<Int32T> tmp393;
    ca_.Bind(&block16, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393);
    ca_.Goto(&block1, tmp386, tmp387, tmp388, tmp389);
  }

  if (block2.is_used()) {
    TNode<Context> tmp394;
    TNode<JSReceiver> tmp395;
    TNode<Object> tmp396;
    TNode<Object> tmp397;
    ca_.Bind(&block2, &tmp394, &tmp395, &tmp396, &tmp397);
    CodeStubAssembler(state_).CallRuntime(Runtime::kCreateDataProperty, tmp394, tmp395, tmp396, tmp397);
    ca_.Goto(&block1, tmp394, tmp395, tmp396, tmp397);
  }

  if (block1.is_used()) {
    TNode<Context> tmp399;
    TNode<JSReceiver> tmp400;
    TNode<Object> tmp401;
    TNode<Object> tmp402;
    ca_.Bind(&block1, &tmp399, &tmp400, &tmp401, &tmp402);
    TNode<Oddball> tmp403;
    USE(tmp403);
    tmp403 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp403);
  }
}

TNode<String> ToStringImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject, String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject, JSReceiver> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, PrimitiveHeapObject> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, PrimitiveHeapObject, Symbol> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block4, tmp0, tmp1, tmp1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
    TNode<Number> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = Cast_Number_0(state_, TNode<Object>{tmp8}, &label0);
    ca_.Goto(&block7, tmp6, tmp7, tmp8, tmp8, tmp8, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp6, tmp7, tmp8, tmp8, tmp8);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block8, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<String> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_String_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp13)}, &label0);
    ca_.Goto(&block11, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13), tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13));
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Number> tmp21;
    ca_.Bind(&block7, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<String> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).NumberToString(TNode<Number>{tmp21});
    ca_.Goto(&block1, tmp16, tmp17, tmp22);
  }

  if (block12.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<HeapObject> tmp27;
    ca_.Bind(&block12, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<Oddball> tmp28;
    USE(tmp28);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp28 = Cast_Oddball_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp26)}, &label0);
    ca_.Goto(&block15, tmp23, tmp24, tmp25, tmp26, ca_.UncheckedCast<HeapObject>(tmp26), tmp28);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp23, tmp24, tmp25, tmp26, ca_.UncheckedCast<HeapObject>(tmp26));
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<HeapObject> tmp33;
    TNode<String> tmp34;
    ca_.Bind(&block11, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    ca_.Goto(&block1, tmp29, tmp30, tmp34);
  }

  if (block16.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<HeapObject> tmp39;
    ca_.Bind(&block16, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<JSReceiver> tmp40;
    USE(tmp40);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp40 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp38)}, &label0);
    ca_.Goto(&block19, tmp35, tmp36, tmp37, tmp38, ca_.UncheckedCast<HeapObject>(tmp38), tmp40);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp35, tmp36, tmp37, tmp38, ca_.UncheckedCast<HeapObject>(tmp38));
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<HeapObject> tmp45;
    TNode<Oddball> tmp46;
    ca_.Bind(&block15, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<IntPtrT> tmp47 = ca_.IntPtrConstant(Oddball::kToStringOffset);
    USE(tmp47);
    TNode<String>tmp48 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp46, tmp47});
    ca_.Goto(&block1, tmp41, tmp42, tmp48);
  }

  if (block20.is_used()) {
    TNode<Context> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<HeapObject> tmp53;
    ca_.Bind(&block20, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<Symbol> tmp54;
    USE(tmp54);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp54 = Cast_Symbol_0(state_, TNode<HeapObject>{ca_.UncheckedCast<PrimitiveHeapObject>(tmp52)}, &label0);
    ca_.Goto(&block23, tmp49, tmp50, tmp51, tmp52, ca_.UncheckedCast<PrimitiveHeapObject>(tmp52), tmp54);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block24, tmp49, tmp50, tmp51, tmp52, ca_.UncheckedCast<PrimitiveHeapObject>(tmp52));
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<HeapObject> tmp59;
    TNode<JSReceiver> tmp60;
    ca_.Bind(&block19, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    TNode<Object> tmp61;
    tmp61 = CodeStubAssembler(state_).CallBuiltin(Builtins::kNonPrimitiveToPrimitive_String, tmp55, tmp57);
    USE(tmp61);
    ca_.Goto(&block4, tmp55, tmp56, tmp61);
  }

  if (block24.is_used()) {
    TNode<Context> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<PrimitiveHeapObject> tmp66;
    ca_.Bind(&block24, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    TNode<String> tmp67;
    tmp67 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kToStringRT, tmp62, tmp63)); 
    USE(tmp67);
    ca_.Goto(&block1, tmp62, tmp63, tmp67);
  }

  if (block23.is_used()) {
    TNode<Context> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<PrimitiveHeapObject> tmp72;
    TNode<Symbol> tmp73;
    ca_.Bind(&block23, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp68}, MessageTemplate::kSymbolToString);
  }

  if (block3.is_used()) {
    TNode<Context> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block3, &tmp74, &tmp75, &tmp76);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<Context> tmp77;
    TNode<Object> tmp78;
    TNode<String> tmp79;
    ca_.Bind(&block1, &tmp77, &tmp78, &tmp79);
    ca_.Goto(&block25, tmp77, tmp78, tmp79);
  }

    TNode<Context> tmp80;
    TNode<Object> tmp81;
    TNode<String> tmp82;
    ca_.Bind(&block25, &tmp80, &tmp81, &tmp82);
  return TNode<String>{tmp82};
}

void VerifiedUnreachable_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp0});
    CodeStubAssembler(state_).Unreachable();
  }
}

TNode<BoolT> Float64IsSomeInfinity_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_value);

  if (block0.is_used()) {
    TNode<Float64T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp0}, TNode<Float64T>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Float64T> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Float64T> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<Float64T> tmp6;
    USE(tmp6);
    tmp6 = Convert_float64_constexpr_int31_0(state_, 0);
    TNode<Float64T> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    TNode<Float64T> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp6}, TNode<Float64T>{tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp5}, TNode<Float64T>{tmp8});
    ca_.Goto(&block1, tmp5, tmp9);
  }

  if (block1.is_used()) {
    TNode<Float64T> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block1, &tmp10, &tmp11);
    ca_.Goto(&block4, tmp10, tmp11);
  }

    TNode<Float64T> tmp12;
    TNode<BoolT> tmp13;
    ca_.Bind(&block4, &tmp12, &tmp13);
  return TNode<BoolT>{tmp13};
}

TNode<BoolT> IsIntegerOrSomeInfinity_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, HeapNumber> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapNumber> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapNumber> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    TNode<HeapNumber> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_HeapNumber_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block8, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp6, tmp10);
  }

  if (block9.is_used()) {
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block9, &tmp11, &tmp12, &tmp13);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp11, tmp14);
  }

  if (block8.is_used()) {
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapNumber> tmp18;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Float64T> tmp19;
    USE(tmp19);
    tmp19 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{tmp18});
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = Float64IsSomeInfinity_0(state_, TNode<Float64T>{tmp19});
    ca_.Branch(tmp20, &block10, &block11, tmp15, tmp16, tmp18);
  }

  if (block10.is_used()) {
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<HeapNumber> tmp23;
    ca_.Bind(&block10, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp21, tmp24);
  }

  if (block11.is_used()) {
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<HeapNumber> tmp27;
    ca_.Bind(&block11, &tmp25, &tmp26, &tmp27);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IsInteger(TNode<HeapNumber>{tmp27});
    ca_.Goto(&block1, tmp25, tmp28);
  }

  if (block1.is_used()) {
    TNode<Object> tmp29;
    TNode<BoolT> tmp30;
    ca_.Bind(&block1, &tmp29, &tmp30);
    ca_.Goto(&block12, tmp29, tmp30);
  }

    TNode<Object> tmp31;
    TNode<BoolT> tmp32;
    ca_.Bind(&block12, &tmp31, &tmp32);
  return TNode<BoolT>{tmp32};
}

TF_BUILTIN(CheckNumberInRange, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Number> parameter1 = UncheckedCast<Number>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Number> parameter2 = UncheckedCast<Number>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Number> parameter3 = UncheckedCast<Number>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Number> tmp1;
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = IsIntegerOrSomeInfinity_0(state_, TNode<Object>{tmp1});
    ca_.Branch(tmp4, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<BoolT> tmp9;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = NumberIsLessThanOrEqual_0(state_, TNode<Number>{tmp7}, TNode<Number>{tmp6});
    ca_.Goto(&block5, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block4.is_used()) {
    TNode<Context> tmp11;
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block4, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block5, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<Number> tmp18;
    TNode<Number> tmp19;
    TNode<Number> tmp20;
    TNode<BoolT> tmp21;
    TNode<BoolT> tmp22;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Branch(tmp22, &block6, &block7, tmp17, tmp18, tmp19, tmp20, tmp22);
  }

  if (block6.is_used()) {
    TNode<Context> tmp23;
    TNode<Number> tmp24;
    TNode<Number> tmp25;
    TNode<Number> tmp26;
    TNode<BoolT> tmp27;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = NumberIsLessThanOrEqual_0(state_, TNode<Number>{tmp24}, TNode<Number>{tmp26});
    ca_.Goto(&block8, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<Number> tmp30;
    TNode<Number> tmp31;
    TNode<Number> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34);
  }

  if (block8.is_used()) {
    TNode<Context> tmp35;
    TNode<Number> tmp36;
    TNode<Number> tmp37;
    TNode<Number> tmp38;
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block8, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    ca_.Branch(tmp40, &block1, &block2, tmp35, tmp36, tmp37, tmp38);
  }

  if (block1.is_used()) {
    TNode<Context> tmp41;
    TNode<Number> tmp42;
    TNode<Number> tmp43;
    TNode<Number> tmp44;
    ca_.Bind(&block1, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<Oddball> tmp45;
    USE(tmp45);
    tmp45 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp45);
  }

  if (block2.is_used()) {
    TNode<Context> tmp46;
    TNode<Number> tmp47;
    TNode<Number> tmp48;
    TNode<Number> tmp49;
    ca_.Bind(&block2, &tmp46, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).Print("Range type assertion failed! (value/min/max)");
    CodeStubAssembler(state_).Print(TNode<Object>{tmp47});
    CodeStubAssembler(state_).Print(TNode<Object>{tmp48});
    CodeStubAssembler(state_).Print(TNode<Object>{tmp49});
    CodeStubAssembler(state_).Unreachable();
  }
}

TNode<Object> ReplaceTheHoleWithUndefined_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Oddball> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_TheHole_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    ca_.Goto(&block1, tmp2, ca_.UncheckedCast<Object>(tmp3));
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Undefined_0(state_);
    ca_.Goto(&block1, tmp5, tmp9);
  }

  if (block1.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp10, &tmp11);
    ca_.Goto(&block6, tmp10, tmp11);
  }

    TNode<Object> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block6, &tmp12, &tmp13);
  return TNode<Object>{tmp13};
}

TNode<JSFunction> UnsafeCast_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSFunction> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSFunction> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSFunction>{tmp9};
}

TNode<JSReceiver> UnsafeCast_Constructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSReceiver> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSReceiver>{tmp9};
}

TNode<Map> UnsafeCast_Map_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Map> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Map> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Map>{tmp9};
}

TNode<JSReceiver> UnsafeCast_Callable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSReceiver> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSReceiver>{tmp9};
}

TNode<BoolT> Is_FastJSArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_FastJSArrayForRead_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArrayForRead_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_FastJSArrayWithNoCustomIteration_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArrayWithNoCustomIteration_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_FastJSArrayForReadWithNoCustomIteration_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArrayForReadWithNoCustomIteration_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<Float64T> Convert_float64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Float64T> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_float64_constexpr_int31_0(state_, p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Float64T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Float64T>{tmp1};
}

TNode<BoolT> Is_JSArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_NumberDictionary_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, NumberDictionary> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<NumberDictionary> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_NumberDictionary_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<NumberDictionary> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSAny_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSAny_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_FixedDoubleArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, FixedDoubleArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<FixedDoubleArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FixedDoubleArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<FixedDoubleArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSTypedArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSTypedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSTypedArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSTypedArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSTypedArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_HeapObject_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_HeapObject_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Smi_OR_HeapNumber_OR_TheHole_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_OR_HeapNumber_OR_TheHole_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_Smi_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_Context_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Context> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Context_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<Context> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_JSFunction_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSFunction> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSFunction> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSFunction_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSFunction> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Constructor_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Constructor_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Map_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Map> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Map_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<Map> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Callable_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<JSArray> Cast_FastJSArrayForReadWithNoCustomIteration_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FastJSArrayForReadWithNoCustomIteration_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArray> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArray>{tmp22};
}

TNode<BoolT> Is_Boolean_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Oddball> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Boolean_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_JSReceiver_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSPrimitiveWrapper_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSPrimitiveWrapper> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPrimitiveWrapper> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSPrimitiveWrapper_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSPrimitiveWrapper> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_ContextOrFrameType_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_ContextOrFrameType_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_CoverageInfo_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_CoverageInfo_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<FixedArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Number_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Number_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_PromiseFulfillReactionJobTask_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, PromiseFulfillReactionJobTask> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseFulfillReactionJobTask> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_PromiseFulfillReactionJobTask_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<PromiseFulfillReactionJobTask> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_PromiseRejectReactionJobTask_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, PromiseRejectReactionJobTask> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<PromiseRejectReactionJobTask> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_PromiseRejectReactionJobTask_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<PromiseRejectReactionJobTask> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Zero_OR_PromiseReaction_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_SharedFunctionInfo_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, SharedFunctionInfo> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<SharedFunctionInfo> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_SharedFunctionInfo_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<SharedFunctionInfo> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSPromise_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSPromise> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSPromise> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSPromise_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSPromise> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSProxy_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSProxy> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSProxy> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSProxy_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSProxy> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSRegExp_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSRegExp_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSRegExp> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_FastJSRegExp_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSRegExp_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSRegExp> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_JSRegExpResult_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSRegExpResult_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_String_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_String_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<String> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_PositiveSmi_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_PositiveSmi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> Is_Symbol_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Symbol> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Symbol> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Symbol_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<Symbol> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_Numeric_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Numeric> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Numeric> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Numeric_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Numeric> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<JSArgumentsObject> Cast_JSArgumentsObjectWithLength_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArgumentsObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArgumentsObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSArgumentsObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSArgumentsObjectWithLength_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArgumentsObject> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArgumentsObject> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArgumentsObject>{tmp22};
}

TNode<BoolT> Is_JSObject_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSObject_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSObject> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<BoolT> Is_HeapNumber_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, HeapNumber> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapNumber> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_HeapNumber_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<HeapNumber> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

TNode<NumberDictionary> Cast_NumberDictionary_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, NumberDictionary> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, NumberDictionary> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<NumberDictionary> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_NumberDictionary_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<NumberDictionary> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<NumberDictionary> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<NumberDictionary>{tmp20};
}

TNode<Map> Cast_Map_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Map> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<Map> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_Map_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<Map> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<Map> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<Map>{tmp22};
}

TNode<JSPrimitiveWrapper> Cast_JSPrimitiveWrapper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSPrimitiveWrapper> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPrimitiveWrapper> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSPrimitiveWrapper> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSPrimitiveWrapper_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSPrimitiveWrapper> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSPrimitiveWrapper> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSPrimitiveWrapper>{tmp20};
}

TNode<FixedArray> Cast_CoverageInfo_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<FixedArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_CoverageInfo_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<FixedArray> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<FixedArray> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<FixedArray>{tmp22};
}

TNode<PromiseFulfillReactionJobTask> Cast_PromiseFulfillReactionJobTask_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, PromiseFulfillReactionJobTask> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseFulfillReactionJobTask> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<PromiseFulfillReactionJobTask> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_PromiseFulfillReactionJobTask_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<PromiseFulfillReactionJobTask> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<PromiseFulfillReactionJobTask> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<PromiseFulfillReactionJobTask>{tmp20};
}

TNode<PromiseRejectReactionJobTask> Cast_PromiseRejectReactionJobTask_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, PromiseRejectReactionJobTask> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseRejectReactionJobTask> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<PromiseRejectReactionJobTask> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_PromiseRejectReactionJobTask_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<PromiseRejectReactionJobTask> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<PromiseRejectReactionJobTask> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<PromiseRejectReactionJobTask>{tmp20};
}

TNode<SharedFunctionInfo> Cast_SharedFunctionInfo_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, SharedFunctionInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, SharedFunctionInfo> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<SharedFunctionInfo> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_SharedFunctionInfo_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<SharedFunctionInfo> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<SharedFunctionInfo> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<SharedFunctionInfo>{tmp20};
}

TNode<JSPromise> Cast_JSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSPromise> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSPromise> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSPromise> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSPromise_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSPromise> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSPromise> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSPromise>{tmp20};
}

TNode<JSObject> Cast_JSObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSObject_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSObject> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSObject> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSObject>{tmp20};
}

TNode<HeapNumber> Cast_HeapNumber_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapNumber> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapNumber> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<HeapNumber> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<HeapNumber> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<HeapNumber> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<HeapNumber>{tmp20};
}

}  // namespace internal
}  // namespace v8

