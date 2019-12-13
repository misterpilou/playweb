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

TNode<Oddball> Cast_Undefined_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<MaybeObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedNotEqual(TNode<MaybeObject>{tmp0}, TNode<MaybeObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<MaybeObject> tmp3;
    ca_.Bind(&block3, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block4.is_used()) {
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<MaybeObject>{tmp4});
    ca_.Goto(&block5, tmp4, tmp5);
  }

    TNode<MaybeObject> tmp6;
    TNode<Oddball> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Oddball>{tmp7};
}

TNode<Smi> Cast_Smi_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).TaggedToSmi(TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Object> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<Smi>{tmp8};
}

TNode<Smi> Cast_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).TaggedToPositiveSmi(TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Object> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<Smi>{tmp8};
}

TNode<Smi> Cast_Zero_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp0}, TNode<MaybeObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.Goto(&block5, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp5);
    ca_.Goto(label_CastError);
  }

    TNode<Object> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Smi>{tmp7};
}

TNode<Number> Cast_Number_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).TaggedToNumber(TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Object> tmp7;
    TNode<Number> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<Number>{tmp8};
}

TNode<Oddball> Cast_Undefined_1(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, MaybeObject, MaybeObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, MaybeObject, MaybeObject, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Undefined_0(state_, TNode<MaybeObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<MaybeObject> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<Object> tmp5;
    TNode<MaybeObject> tmp6;
    TNode<MaybeObject> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<Object> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<Numeric> Cast_Numeric_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, BigInt> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Numeric> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Numeric> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Number_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<BigInt> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_BigInt_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Number> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<BigInt> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Numeric> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Numeric> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Numeric>{tmp20};
}

TNode<Oddball> Cast_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = TheHole_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.Goto(&block5, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp5);
    ca_.Goto(label_CastError);
  }

    TNode<Object> tmp6;
    TNode<Oddball> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Oddball>{tmp7};
}

TNode<Oddball> Cast_TheHole_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_TheHole_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<Oddball> Cast_True_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = True_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.Goto(&block5, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp5);
    ca_.Goto(label_CastError);
  }

    TNode<Object> tmp6;
    TNode<Oddball> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Oddball>{tmp7};
}

TNode<Oddball> Cast_True_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_True_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<Oddball> Cast_False_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = False_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = TORQUE_CAST(TNode<Object>{tmp3});
    ca_.Goto(&block5, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp5);
    ca_.Goto(label_CastError);
  }

    TNode<Object> tmp6;
    TNode<Oddball> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Oddball>{tmp7};
}

TNode<Oddball> Cast_False_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_False_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<Oddball> Cast_Boolean_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_True_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_False_0(state_, TNode<Object>{ca_.UncheckedCast<Object>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<Object>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<Object>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Oddball> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Oddball> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Oddball> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Oddball> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Oddball>{tmp20};
}

TNode<Oddball> Cast_Boolean_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Object, Object, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Boolean_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<Object> Cast_JSPrimitive_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Numeric> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, String> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Symbol> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Oddball> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Oddball> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Oddball> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Numeric> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Numeric_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_String_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Numeric> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    TNode<Symbol> tmp13;
    USE(tmp13);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp13 = Cast_Symbol_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp11)}, &label0);
    ca_.Goto(&block13, tmp10, tmp11, ca_.UncheckedCast<HeapObject>(tmp11), tmp13);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp10, tmp11, ca_.UncheckedCast<HeapObject>(tmp11));
    }
  }

  if (block9.is_used()) {
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<String> tmp17;
    ca_.Bind(&block9, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block2, tmp14, tmp17);
  }

  if (block14.is_used()) {
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<HeapObject> tmp20;
    ca_.Bind(&block14, &tmp18, &tmp19, &tmp20);
    TNode<Oddball> tmp21;
    USE(tmp21);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp21 = Cast_Boolean_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp19)}, &label0);
    ca_.Goto(&block17, tmp18, tmp19, ca_.UncheckedCast<HeapObject>(tmp19), tmp21);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp18, tmp19, ca_.UncheckedCast<HeapObject>(tmp19));
    }
  }

  if (block13.is_used()) {
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    TNode<HeapObject> tmp24;
    TNode<Symbol> tmp25;
    ca_.Bind(&block13, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block2, tmp22, tmp25);
  }

  if (block18.is_used()) {
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<HeapObject> tmp28;
    ca_.Bind(&block18, &tmp26, &tmp27, &tmp28);
    TNode<Oddball> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = Cast_Undefined_2(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp27)}, &label0);
    ca_.Goto(&block21, tmp26, tmp27, ca_.UncheckedCast<HeapObject>(tmp27), tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block22, tmp26, tmp27, ca_.UncheckedCast<HeapObject>(tmp27));
    }
  }

  if (block17.is_used()) {
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<HeapObject> tmp32;
    TNode<Oddball> tmp33;
    ca_.Bind(&block17, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block2, tmp30, tmp33);
  }

  if (block22.is_used()) {
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    TNode<HeapObject> tmp36;
    ca_.Bind(&block22, &tmp34, &tmp35, &tmp36);
    TNode<Oddball> tmp37;
    USE(tmp37);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp37 = Cast_Null_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp35)}, &label0);
    ca_.Goto(&block25, tmp34, tmp35, ca_.UncheckedCast<HeapObject>(tmp35), tmp37);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block26, tmp34, tmp35, ca_.UncheckedCast<HeapObject>(tmp35));
    }
  }

  if (block21.is_used()) {
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<HeapObject> tmp40;
    TNode<Oddball> tmp41;
    ca_.Bind(&block21, &tmp38, &tmp39, &tmp40, &tmp41);
    ca_.Goto(&block2, tmp38, tmp41);
  }

  if (block26.is_used()) {
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<HeapObject> tmp44;
    ca_.Bind(&block26, &tmp42, &tmp43, &tmp44);
    ca_.Goto(label_CastError);
  }

  if (block25.is_used()) {
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    TNode<HeapObject> tmp47;
    TNode<Oddball> tmp48;
    ca_.Bind(&block25, &tmp45, &tmp46, &tmp47, &tmp48);
    ca_.Goto(&block2, tmp45, tmp48);
  }

  if (block2.is_used()) {
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block2, &tmp49, &tmp50);
    ca_.Goto(&block27, tmp49, tmp50);
  }

    TNode<Object> tmp51;
    TNode<Object> tmp52;
    ca_.Bind(&block27, &tmp51, &tmp52);
  return TNode<Object>{tmp52};
}

TNode<Object> Cast_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Object> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_JSPrimitive_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<JSReceiver> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Object>{tmp20};
}

TNode<Object> Cast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Object> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_JSAny_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_TheHole_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<Oddball> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Object>{tmp20};
}

TNode<Object> Cast_Smi_OR_HeapNumber_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Number_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_TheHole_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Number> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<Oddball> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Object>{tmp20};
}

TNode<HeapObject> Cast_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label__CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block3, tmp0, tmp0);
  }

    TNode<HeapObject> tmp1;
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp1, &tmp2);
  return TNode<HeapObject>{tmp2};
}

TNode<Oddball> Cast_Null_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Null_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp3;
    ca_.Bind(&block3, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp4, tmp5);
  }

    TNode<HeapObject> tmp6;
    TNode<Oddball> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<Oddball>{tmp7};
}

TNode<Oddball> Cast_Undefined_2(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, MaybeObject, MaybeObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, MaybeObject, MaybeObject, Oddball> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Undefined_0(state_, TNode<MaybeObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<MaybeObject> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    TNode<MaybeObject> tmp6;
    TNode<MaybeObject> tmp7;
    TNode<Oddball> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp8);
  }

    TNode<HeapObject> tmp9;
    TNode<Oddball> tmp10;
    ca_.Bind(&block5, &tmp9, &tmp10);
  return TNode<Oddball>{tmp10};
}

TNode<FixedArray> Cast_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, FixedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToFixedArray(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<FixedArray> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<FixedArray> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<FixedArray>{tmp8};
}

TNode<FixedDoubleArray> Cast_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, FixedDoubleArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, FixedDoubleArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedDoubleArray> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToFixedDoubleArray(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<FixedDoubleArray> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<FixedDoubleArray> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<FixedDoubleArray>{tmp8};
}

TNode<FixedArray> Cast_SloppyArgumentsElements_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, FixedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToSloppyArgumentsElements(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<FixedArray> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<FixedArray> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<FixedArray>{tmp8};
}

TNode<JSDataView> Cast_JSDataView_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSDataView> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSDataView> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSDataView> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSDataView(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSDataView> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSDataView> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSDataView>{tmp8};
}

TNode<JSProxy> Cast_JSProxy_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSProxy> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSProxy> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSProxy> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSProxy(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSProxy> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSProxy> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSProxy>{tmp8};
}

TNode<JSStringIterator> Cast_JSStringIterator_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSStringIterator> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSStringIterator> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSStringIterator> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSStringIterator(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSStringIterator> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSStringIterator> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSStringIterator>{tmp8};
}

TNode<JSRegExpStringIterator> Cast_JSRegExpStringIterator_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSRegExpStringIterator> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSRegExpStringIterator(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSRegExpStringIterator> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSRegExpStringIterator> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSRegExpStringIterator>{tmp6};
}

TNode<JSTypedArray> Cast_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSTypedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSTypedArray(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSTypedArray> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSTypedArray> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSTypedArray>{tmp6};
}

TNode<JSTypedArray> Cast_JSTypedArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject, JSTypedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSTypedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_HeapObject_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Context> tmp10;
    TNode<HeapObject> tmp11;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<JSTypedArray> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{tmp11}, &label0);
    ca_.Goto(&block5, tmp7, tmp8, tmp11, tmp11, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp7, tmp8, tmp11, tmp11);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<HeapObject> tmp16;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<HeapObject> tmp19;
    TNode<HeapObject> tmp20;
    TNode<JSTypedArray> tmp21;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block7, tmp17, tmp18, tmp21);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<JSTypedArray> tmp24;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24);
  return TNode<JSTypedArray>{tmp24};
}

TNode<JSReceiver> Cast_Callable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSReceiver> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToCallable(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSReceiver> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSReceiver>{tmp8};
}

TNode<HeapObject> Cast_Undefined_OR_CallableApiObject_OR_CallableJSProxy_OR_JSFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp3;
    ca_.Bind(&block3, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    ca_.Goto(&block2, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp5;
    ca_.Bind(&block4, &tmp5);
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = CodeStubAssembler(state_).HeapObjectToCallable(TNode<HeapObject>{tmp5}, &label0);
    ca_.Goto(&block5, tmp5, tmp5, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp5, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<HeapObject> tmp7;
    TNode<HeapObject> tmp8;
    ca_.Bind(&block6, &tmp7, &tmp8);
    ca_.Goto(label_CastError);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp9;
    TNode<HeapObject> tmp10;
    TNode<JSReceiver> tmp11;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block2, tmp9, tmp11);
  }

  if (block2.is_used()) {
    TNode<HeapObject> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block2, &tmp12, &tmp13);
    ca_.Goto(&block7, tmp12, tmp13);
  }

    TNode<HeapObject> tmp14;
    TNode<HeapObject> tmp15;
    ca_.Bind(&block7, &tmp14, &tmp15);
  return TNode<HeapObject>{tmp15};
}

TNode<JSArray> Cast_JSArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSArray> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSArray(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSArray> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSArray> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSArray>{tmp8};
}

TNode<JSArrayBuffer> Cast_JSArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSArrayBuffer> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSArrayBuffer> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSArrayBuffer> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSArrayBuffer(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSArrayBuffer> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSArrayBuffer> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSArrayBuffer>{tmp8};
}

TNode<Context> Cast_Context_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsContext(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<Context> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Context>{tmp6};
}

TNode<NativeContext> Cast_NativeContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, NativeContext> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<NativeContext> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<NativeContext> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<NativeContext>{tmp6};
}

TNode<JSObject> Cast_JSObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSObject(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSObject> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSObject> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSObject>{tmp6};
}

TNode<NumberDictionary> Cast_NumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, NumberDictionary> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsNumberDictionary(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<NumberDictionary> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<NumberDictionary> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<NumberDictionary>{tmp6};
}

TNode<String> Cast_String_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<String> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToString(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<String> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<String> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<String>{tmp8};
}

TNode<Oddball> Cast_Oddball_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsOddball(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<Oddball> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Oddball>{tmp6};
}

TNode<Symbol> Cast_Symbol_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsSymbol(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<Symbol> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<Symbol> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Symbol>{tmp6};
}

TNode<Symbol> Cast_PublicSymbol_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Symbol> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPrivateSymbol(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Symbol> tmp2;
    ca_.Bind(&block3, &tmp2);
    ca_.Goto(label_CastError);
  }

  if (block4.is_used()) {
    TNode<Symbol> tmp3;
    ca_.Bind(&block4, &tmp3);
    TNode<Symbol> tmp4;
    USE(tmp4);
    tmp4 = (TNode<Symbol>{tmp3});
    ca_.Goto(&block5, tmp3, tmp4);
  }

    TNode<Symbol> tmp5;
    TNode<Symbol> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Symbol>{tmp6};
}

TNode<Symbol> Cast_PrivateSymbol_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Symbol, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Symbol> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPrivateSymbol(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Symbol> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<Symbol> tmp3;
    USE(tmp3);
    tmp3 = (TNode<Symbol>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<Symbol> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<Symbol> tmp5;
    TNode<Symbol> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Symbol>{tmp6};
}

TNode<Symbol> Cast_PublicSymbol_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, Symbol> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol, Symbol> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol, Symbol, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Symbol> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Symbol_0(state_, TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<Symbol> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    TNode<Symbol> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_PublicSymbol_0(state_, TNode<Symbol>{tmp6}, &label0);
    ca_.Goto(&block5, tmp4, tmp6, tmp6, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp4, tmp6, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<HeapObject> tmp8;
    TNode<Symbol> tmp9;
    TNode<Symbol> tmp10;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp11;
    TNode<Symbol> tmp12;
    TNode<Symbol> tmp13;
    TNode<Symbol> tmp14;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block7, tmp11, tmp14);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp15;
    TNode<Symbol> tmp16;
    ca_.Bind(&block7, &tmp15, &tmp16);
  return TNode<Symbol>{tmp16};
}

TNode<Symbol> Cast_PrivateSymbol_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, Symbol> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol, Symbol> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol, Symbol, Symbol> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, Symbol> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Symbol> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Symbol_0(state_, TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<Symbol> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    TNode<Symbol> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_PrivateSymbol_0(state_, TNode<Symbol>{tmp6}, &label0);
    ca_.Goto(&block5, tmp4, tmp6, tmp6, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp4, tmp6, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<HeapObject> tmp8;
    TNode<Symbol> tmp9;
    TNode<Symbol> tmp10;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp11;
    TNode<Symbol> tmp12;
    TNode<Symbol> tmp13;
    TNode<Symbol> tmp14;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block7, tmp11, tmp14);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp15;
    TNode<Symbol> tmp16;
    ca_.Bind(&block7, &tmp15, &tmp16);
  return TNode<Symbol>{tmp16};
}

TNode<String> Cast_DirectString_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<String> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).TaggedToDirectString(TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<String> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<String> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<String>{tmp8};
}

TNode<JSReceiver> Cast_Constructor_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSReceiver> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToConstructor(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSReceiver> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSReceiver>{tmp8};
}

TNode<JSFunction> Cast_JSFunctionWithPrototypeSlot_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSFunction> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = CodeStubAssembler(state_).HeapObjectToJSFunctionWithPrototypeSlot(TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<JSFunction> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<HeapObject> tmp7;
    TNode<JSFunction> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<JSFunction>{tmp8};
}

TNode<HeapNumber> Cast_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapNumber> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsHeapNumber(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<HeapNumber> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<HeapNumber> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<HeapNumber>{tmp6};
}

TNode<BigInt> Cast_BigInt_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsBigInt(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<BigInt> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<BigInt> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<BigInt>{tmp6};
}

TNode<JSRegExp> Cast_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSRegExp> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSRegExp(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSRegExp> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSRegExp> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSRegExp>{tmp6};
}

TNode<JSArray> Cast_JSRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsRegExpResult_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<JSArray> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<JSArray> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<JSArray>{tmp10};
}

TNode<Map> Cast_Map_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsMap(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<Map> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<Map> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<Map>{tmp10};
}

TNode<FeedbackVector> Cast_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, FeedbackVector> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsFeedbackVector(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<FeedbackVector> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<FeedbackVector> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<FeedbackVector>{tmp10};
}

TNode<JSPrimitiveWrapper> Cast_JSPrimitiveWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSPrimitiveWrapper> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSPrimitiveWrapper(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSPrimitiveWrapper> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSPrimitiveWrapper> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSPrimitiveWrapper>{tmp6};
}

TNode<JSArgumentsObject> Cast_JSSloppyArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, BoolT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArgumentsObject> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp2);
    TNode<Map>tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IsFastAliasedArgumentsMap(TNode<Context>{tmp0}, TNode<Map>{tmp3});
    ca_.Branch(tmp4, &block5, &block6, tmp0, tmp1, tmp3, tmp4);
  }

  if (block5.is_used()) {
    TNode<Context> tmp5;
    TNode<HeapObject> tmp6;
    TNode<Map> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block5, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block7, tmp5, tmp6, tmp7, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Context> tmp10;
    TNode<HeapObject> tmp11;
    TNode<Map> tmp12;
    TNode<BoolT> tmp13;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).IsSloppyArgumentsMap(TNode<Context>{tmp10}, TNode<Map>{tmp12});
    ca_.Goto(&block7, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block7.is_used()) {
    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<Map> tmp17;
    TNode<BoolT> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block7, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Branch(tmp19, &block8, &block9, tmp15, tmp16, tmp17, tmp19);
  }

  if (block8.is_used()) {
    TNode<Context> tmp20;
    TNode<HeapObject> tmp21;
    TNode<Map> tmp22;
    TNode<BoolT> tmp23;
    ca_.Bind(&block8, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block10, tmp20, tmp21, tmp22, tmp23, tmp24);
  }

  if (block9.is_used()) {
    TNode<Context> tmp25;
    TNode<HeapObject> tmp26;
    TNode<Map> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block9, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).IsSlowAliasedArgumentsMap(TNode<Context>{tmp25}, TNode<Map>{tmp27});
    ca_.Goto(&block10, tmp25, tmp26, tmp27, tmp28, tmp29);
  }

  if (block10.is_used()) {
    TNode<Context> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Map> tmp32;
    TNode<BoolT> tmp33;
    TNode<BoolT> tmp34;
    ca_.Bind(&block10, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    ca_.Branch(tmp34, &block3, &block4, tmp30, tmp31, tmp32);
  }

  if (block3.is_used()) {
    TNode<Context> tmp35;
    TNode<HeapObject> tmp36;
    TNode<Map> tmp37;
    ca_.Bind(&block3, &tmp35, &tmp36, &tmp37);
    TNode<JSArgumentsObject> tmp38;
    USE(tmp38);
    tmp38 = TORQUE_CAST(TNode<HeapObject>{tmp36});
    ca_.Goto(&block11, tmp35, tmp36, tmp38);
  }

  if (block4.is_used()) {
    TNode<Context> tmp39;
    TNode<HeapObject> tmp40;
    TNode<Map> tmp41;
    ca_.Bind(&block4, &tmp39, &tmp40, &tmp41);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp42;
    TNode<HeapObject> tmp43;
    TNode<JSArgumentsObject> tmp44;
    ca_.Bind(&block11, &tmp42, &tmp43, &tmp44);
  return TNode<JSArgumentsObject>{tmp44};
}

TNode<JSArgumentsObject> Cast_JSStrictArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArgumentsObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp2);
    TNode<Map>tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IsStrictArgumentsMap(TNode<Context>{tmp0}, TNode<Map>{tmp3});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    TNode<Map> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    ca_.Goto(label_CastError);
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Map> tmp11;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11);
    TNode<JSArgumentsObject> tmp12;
    USE(tmp12);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp10});
    ca_.Goto(&block5, tmp9, tmp10, tmp12);
  }

    TNode<Context> tmp13;
    TNode<HeapObject> tmp14;
    TNode<JSArgumentsObject> tmp15;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15);
  return TNode<JSArgumentsObject>{tmp15};
}

TNode<JSArgumentsObject> Cast_JSArgumentsObjectWithLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context, JSArgumentsObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, HeapObject, Context, JSArgumentsObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArgumentsObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArgumentsObject> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArgumentsObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSStrictArgumentsObject_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    TNode<HeapObject> tmp5;
    TNode<HeapObject> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<JSArgumentsObject> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = Cast_JSSloppyArgumentsObject_0(state_, TNode<Context>{tmp3}, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp5)}, &label0);
    ca_.Goto(&block9, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5), tmp3, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5), tmp3);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<HeapObject> tmp10;
    TNode<HeapObject> tmp11;
    TNode<HeapObject> tmp12;
    TNode<Context> tmp13;
    TNode<JSArgumentsObject> tmp14;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block2, tmp9, tmp10, tmp14);
  }

  if (block10.is_used()) {
    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    TNode<Context> tmp19;
    ca_.Bind(&block10, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Context> tmp20;
    TNode<HeapObject> tmp21;
    TNode<HeapObject> tmp22;
    TNode<HeapObject> tmp23;
    TNode<Context> tmp24;
    TNode<JSArgumentsObject> tmp25;
    ca_.Bind(&block9, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block2, tmp20, tmp21, tmp25);
  }

  if (block2.is_used()) {
    TNode<Context> tmp26;
    TNode<HeapObject> tmp27;
    TNode<JSArgumentsObject> tmp28;
    ca_.Bind(&block2, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block11, tmp26, tmp27, tmp28);
  }

    TNode<Context> tmp29;
    TNode<HeapObject> tmp30;
    TNode<JSArgumentsObject> tmp31;
    ca_.Bind(&block11, &tmp29, &tmp30, &tmp31);
  return TNode<JSArgumentsObject>{tmp31};
}

TNode<JSRegExp> Cast_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSRegExp> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsFastRegExpStrict_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<JSRegExp> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<JSRegExp> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<JSRegExp>{tmp10};
}

TNode<JSArray> Cast_FastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<HeapObject> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp7);
    TNode<Map>tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).IsJSArrayMap(TNode<Map>{tmp8});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp9});
    ca_.Branch(tmp10, &block5, &block6, tmp5, tmp6, tmp8);
  }

  if (block5.is_used()) {
    TNode<Context> tmp11;
    TNode<HeapObject> tmp12;
    TNode<Map> tmp13;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block6.is_used()) {
    TNode<Context> tmp14;
    TNode<HeapObject> tmp15;
    TNode<Map> tmp16;
    ca_.Bind(&block6, &tmp14, &tmp15, &tmp16);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp16});
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).IsFastElementsKind(TNode<Int32T>{tmp17});
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp18});
    ca_.Branch(tmp19, &block7, &block8, tmp14, tmp15, tmp16, tmp17);
  }

  if (block7.is_used()) {
    TNode<Context> tmp20;
    TNode<HeapObject> tmp21;
    TNode<Map> tmp22;
    TNode<Int32T> tmp23;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<Context> tmp24;
    TNode<HeapObject> tmp25;
    TNode<Map> tmp26;
    TNode<Int32T> tmp27;
    ca_.Bind(&block8, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IsPrototypeInitialArrayPrototype(TNode<Context>{tmp24}, TNode<Map>{tmp26});
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp28});
    ca_.Branch(tmp29, &block9, &block10, tmp24, tmp25, tmp26, tmp27);
  }

  if (block9.is_used()) {
    TNode<Context> tmp30;
    TNode<HeapObject> tmp31;
    TNode<Map> tmp32;
    TNode<Int32T> tmp33;
    ca_.Bind(&block9, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    TNode<Context> tmp34;
    TNode<HeapObject> tmp35;
    TNode<Map> tmp36;
    TNode<Int32T> tmp37;
    ca_.Bind(&block10, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp38, &block11, &block12, tmp34, tmp35, tmp36, tmp37);
  }

  if (block11.is_used()) {
    TNode<Context> tmp39;
    TNode<HeapObject> tmp40;
    TNode<Map> tmp41;
    TNode<Int32T> tmp42;
    ca_.Bind(&block11, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    TNode<Context> tmp43;
    TNode<HeapObject> tmp44;
    TNode<Map> tmp45;
    TNode<Int32T> tmp46;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<JSArray> tmp47;
    USE(tmp47);
    tmp47 = TORQUE_CAST(TNode<HeapObject>{tmp44});
    ca_.Goto(&block13, tmp43, tmp44, tmp47);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp48;
    TNode<HeapObject> tmp49;
    TNode<JSArray> tmp50;
    ca_.Bind(&block13, &tmp48, &tmp49, &tmp50);
  return TNode<JSArray>{tmp50};
}

TNode<JSArray> Cast_FastJSArrayForRead_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, Map, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp2);
    TNode<Map>tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IsJSArrayMap(TNode<Map>{tmp3});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp4});
    ca_.Branch(tmp5, &block3, &block4, tmp0, tmp1, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    TNode<Map> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Map> tmp11;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11);
    TNode<Int32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp11});
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).IsElementsKindLessThanOrEqual(TNode<Int32T>{tmp12}, LAST_ANY_NONEXTENSIBLE_ELEMENTS_KIND);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp13});
    ca_.Branch(tmp14, &block5, &block6, tmp9, tmp10, tmp11, tmp12);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<Map> tmp17;
    TNode<Int32T> tmp18;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18);
    ca_.Goto(&block1);
  }

  if (block6.is_used()) {
    TNode<Context> tmp19;
    TNode<HeapObject> tmp20;
    TNode<Map> tmp21;
    TNode<Int32T> tmp22;
    ca_.Bind(&block6, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IsPrototypeInitialArrayPrototype(TNode<Context>{tmp19}, TNode<Map>{tmp21});
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp23});
    ca_.Branch(tmp24, &block7, &block8, tmp19, tmp20, tmp21, tmp22);
  }

  if (block7.is_used()) {
    TNode<Context> tmp25;
    TNode<HeapObject> tmp26;
    TNode<Map> tmp27;
    TNode<Int32T> tmp28;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    TNode<Context> tmp29;
    TNode<HeapObject> tmp30;
    TNode<Map> tmp31;
    TNode<Int32T> tmp32;
    ca_.Bind(&block8, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp33, &block9, &block10, tmp29, tmp30, tmp31, tmp32);
  }

  if (block9.is_used()) {
    TNode<Context> tmp34;
    TNode<HeapObject> tmp35;
    TNode<Map> tmp36;
    TNode<Int32T> tmp37;
    ca_.Bind(&block9, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    TNode<Context> tmp38;
    TNode<HeapObject> tmp39;
    TNode<Map> tmp40;
    TNode<Int32T> tmp41;
    ca_.Bind(&block10, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<JSArray> tmp42;
    USE(tmp42);
    tmp42 = TORQUE_CAST(TNode<HeapObject>{tmp39});
    ca_.Goto(&block11, tmp38, tmp39, tmp42);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp43;
    TNode<HeapObject> tmp44;
    TNode<JSArray> tmp45;
    ca_.Bind(&block11, &tmp43, &tmp44, &tmp45);
  return TNode<JSArray>{tmp45};
}

TNode<JSArray> Cast_FastJSArrayForCopy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsArraySpeciesProtectorCellInvalid();
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<HeapObject> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<JSArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_FastJSArray_0(state_, TNode<Context>{tmp5}, TNode<HeapObject>{tmp6}, &label0);
    ca_.Goto(&block5, tmp5, tmp6, tmp6, tmp5, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp5, tmp6, tmp6, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<HeapObject> tmp14;
    TNode<Context> tmp15;
    TNode<JSArray> tmp16;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<JSArray> tmp17;
    USE(tmp17);
    tmp17 = (TNode<JSArray>{tmp16});
    ca_.Goto(&block7, tmp12, tmp13, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<HeapObject> tmp19;
    TNode<JSArray> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSArray>{tmp20};
}

TNode<JSArray> Cast_FastJSArrayWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsArrayIteratorProtectorCellInvalid();
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<HeapObject> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<JSArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_FastJSArray_0(state_, TNode<Context>{tmp5}, TNode<HeapObject>{tmp6}, &label0);
    ca_.Goto(&block5, tmp5, tmp6, tmp6, tmp5, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp5, tmp6, tmp6, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<HeapObject> tmp14;
    TNode<Context> tmp15;
    TNode<JSArray> tmp16;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<JSArray> tmp17;
    USE(tmp17);
    tmp17 = (TNode<JSArray>{tmp16});
    ca_.Goto(&block7, tmp12, tmp13, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<HeapObject> tmp19;
    TNode<JSArray> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSArray>{tmp20};
}

TNode<JSArray> Cast_FastJSArrayForReadWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsArrayIteratorProtectorCellInvalid();
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<HeapObject> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<JSArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_FastJSArrayForRead_0(state_, TNode<Context>{tmp5}, TNode<HeapObject>{tmp6}, &label0);
    ca_.Goto(&block5, tmp5, tmp6, tmp6, tmp5, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp5, tmp6, tmp6, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<HeapObject> tmp10;
    TNode<Context> tmp11;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<HeapObject> tmp14;
    TNode<Context> tmp15;
    TNode<JSArray> tmp16;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<JSArray> tmp17;
    USE(tmp17);
    tmp17 = (TNode<JSArray>{tmp16});
    ca_.Goto(&block7, tmp12, tmp13, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<HeapObject> tmp19;
    TNode<JSArray> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSArray>{tmp20};
}

TNode<JSReceiver> Cast_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSReceiver(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSReceiver>{tmp6};
}

TNode<JSFunction> Cast_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsJSFunction(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<JSFunction> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<JSFunction> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<JSFunction>{tmp10};
}

TNode<DebugInfo> Cast_DebugInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, DebugInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsDebugInfo(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<DebugInfo> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<DebugInfo> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<DebugInfo>{tmp10};
}

TNode<FixedArray> Cast_CoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IsFixedArray(TNode<HeapObject>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    TNode<FixedArray> tmp5;
    USE(tmp5);
    tmp5 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block5, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<HeapObject> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp8;
    TNode<HeapObject> tmp9;
    TNode<FixedArray> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
  return TNode<FixedArray>{tmp10};
}

TNode<HeapObject> Cast_JSReceiver_OR_Null_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject, HeapObject, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Null_0(state_, TNode<HeapObject>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<HeapObject> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<HeapObject> tmp6;
    TNode<HeapObject> tmp7;
    TNode<HeapObject> tmp8;
    TNode<Oddball> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<HeapObject> tmp10;
    TNode<HeapObject> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<HeapObject> tmp13;
    TNode<HeapObject> tmp14;
    TNode<HeapObject> tmp15;
    TNode<JSReceiver> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<HeapObject> tmp17;
    TNode<HeapObject> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<HeapObject> tmp19;
    TNode<HeapObject> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<HeapObject>{tmp20};
}

TNode<PromiseFulfillReactionJobTask> Cast_PromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, PromiseFulfillReactionJobTask> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPromiseFulfillReactionJobTask(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<PromiseFulfillReactionJobTask> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<PromiseFulfillReactionJobTask> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<PromiseFulfillReactionJobTask>{tmp6};
}

TNode<PromiseRejectReactionJobTask> Cast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, PromiseRejectReactionJobTask> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPromiseRejectReactionJobTask(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<PromiseRejectReactionJobTask> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<PromiseRejectReactionJobTask> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<PromiseRejectReactionJobTask>{tmp6};
}

TNode<PromiseReaction> Cast_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, PromiseReaction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPromiseReaction(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<PromiseReaction> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<PromiseReaction> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<PromiseReaction>{tmp6};
}

TNode<Object> Cast_Smi_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, HeapObject, PromiseReaction> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block5, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp0, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4);
    TNode<PromiseReaction> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_PromiseReaction_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp3)}, &label0);
    ca_.Goto(&block9, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3), tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp2, tmp3, ca_.UncheckedCast<HeapObject>(tmp3));
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9);
    ca_.Goto(&block2, tmp6, tmp9);
  }

  if (block10.is_used()) {
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<HeapObject> tmp12;
    ca_.Bind(&block10, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<HeapObject> tmp15;
    TNode<PromiseReaction> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp13, tmp16);
  }

  if (block2.is_used()) {
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    ca_.Goto(&block11, tmp17, tmp18);
  }

    TNode<Object> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block11, &tmp19, &tmp20);
  return TNode<Object>{tmp20};
}

TNode<HeapObject> Cast_String_OR_CallableApiObject_OR_CallableJSProxy_OR_JSFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_String_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<JSReceiver> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = Cast_Callable_1(state_, TNode<Context>{tmp3}, TNode<Object>{ca_.UncheckedCast<Object>(tmp5)}, &label0);
    ca_.Goto(&block9, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<String> tmp14;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block2, tmp9, tmp10, tmp14);
  }

  if (block10.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Context> tmp19;
    ca_.Bind(&block10, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    TNode<Context> tmp24;
    TNode<JSReceiver> tmp25;
    ca_.Bind(&block9, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block2, tmp20, tmp21, tmp25);
  }

  if (block2.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<HeapObject> tmp28;
    ca_.Bind(&block2, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block11, tmp26, tmp27, tmp28);
  }

    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<HeapObject> tmp31;
    ca_.Bind(&block11, &tmp29, &tmp30, &tmp31);
  return TNode<HeapObject>{tmp31};
}

TNode<Object> Cast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, PromiseReaction> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Zero_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<PromiseReaction> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_PromiseReaction_1(state_, TNode<Context>{tmp3}, TNode<Object>{ca_.UncheckedCast<Object>(tmp5)}, &label0);
    ca_.Goto(&block9, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block2, tmp8, tmp9, tmp12);
  }

  if (block10.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Context> tmp17;
    ca_.Bind(&block10, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(label_CastError);
  }

  if (block9.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Context> tmp22;
    TNode<PromiseReaction> tmp23;
    ca_.Bind(&block9, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block2, tmp18, tmp19, tmp23);
  }

  if (block2.is_used()) {
    TNode<Context> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    ca_.Bind(&block2, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block11, tmp24, tmp25, tmp26);
  }

    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block11, &tmp27, &tmp28, &tmp29);
  return TNode<Object>{tmp29};
}

TNode<JSBoundFunction> Cast_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSBoundFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSBoundFunction(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSBoundFunction> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSBoundFunction> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSBoundFunction>{tmp6};
}

TNode<PromiseCapability> Cast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, PromiseCapability> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsPromiseCapability(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<PromiseCapability> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<PromiseCapability> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<PromiseCapability>{tmp6};
}

TNode<SharedFunctionInfo> Cast_SharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, SharedFunctionInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsSharedFunctionInfo(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<SharedFunctionInfo> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<SharedFunctionInfo> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<SharedFunctionInfo>{tmp6};
}

TNode<JSPromise> Cast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, JSPromise> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsJSPromise(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<JSPromise> tmp3;
    USE(tmp3);
    tmp3 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block5, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_CastError);
  }

    TNode<HeapObject> tmp5;
    TNode<JSPromise> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<JSPromise>{tmp6};
}

TNode<RegExpMatchInfo> UnsafeCast_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RegExpMatchInfo> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<RegExpMatchInfo> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FixedArray>(o)' failed", "src/builtins/cast.tq", 707);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<RegExpMatchInfo> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<RegExpMatchInfo>{tmp9};
}

TNode<HeapObject> Cast_HeapObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, HeapObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<HeapObject> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_HeapObject_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<HeapObject> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<HeapObject> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<HeapObject>{tmp20};
}

TNode<PromiseReaction> Cast_PromiseReaction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, PromiseReaction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, PromiseReaction> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<PromiseReaction> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_PromiseReaction_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<PromiseReaction> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<PromiseReaction> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<PromiseReaction>{tmp20};
}

TNode<BoolT> Is_FixedArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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
    tmp2 = Cast_FixedArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
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

}  // namespace internal
}  // namespace v8

