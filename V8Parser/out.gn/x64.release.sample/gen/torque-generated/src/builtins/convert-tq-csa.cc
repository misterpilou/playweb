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

TNode<Int32T> FromConstexpr_int31_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Int32T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_int32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Int32T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_int32_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Int32T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Int32T>{tmp1};
}

TNode<IntPtrT> FromConstexpr_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = ca_.IntPtrConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TNode<IntPtrT> FromConstexpr_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = ca_.IntPtrConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TNode<IntPtrT> FromConstexpr_intptr_constexpr_intptr_0(compiler::CodeAssemblerState* state_, intptr_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = ca_.IntPtrConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TNode<UintPtrT> FromConstexpr_uintptr_constexpr_uintptr_0(compiler::CodeAssemblerState* state_, uintptr_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<UintPtrT> tmp0;
    USE(tmp0);
    tmp0 = ca_.UintPtrConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<UintPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<UintPtrT>{tmp1};
}

TNode<Smi> FromConstexpr_Smi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = ca_.SmiConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Smi> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Smi>{tmp1};
}

TNode<Smi> FromConstexpr_PositiveSmi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = ca_.SmiConstant(p_i);
    ca_.Goto(&block6, tmp0);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'i >= 0' failed", "src/builtins/convert.tq", 32);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
  }

    TNode<Smi> tmp1;
    ca_.Bind(&block6, &tmp1);
  return TNode<Smi>{tmp1};
}

TNode<String> FromConstexpr_String_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = ca_.StringConstant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<String> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<String>{tmp1};
}

TNode<Number> FromConstexpr_Number_constexpr_uint32_0(compiler::CodeAssemblerState* state_, uint32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Number> tmp0;
    USE(tmp0);
    tmp0 = ca_.NumberConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Number> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Number>{tmp1};
}

TNode<Number> FromConstexpr_Number_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Number> tmp0;
    USE(tmp0);
    tmp0 = ca_.NumberConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Number> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Number>{tmp1};
}

TNode<Number> FromConstexpr_Number_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Number> tmp0;
    USE(tmp0);
    tmp0 = ca_.NumberConstant(p_f);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Number> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Number>{tmp1};
}

TNode<Number> FromConstexpr_Number_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Number> tmp0;
    USE(tmp0);
    tmp0 = ca_.NumberConstant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Number> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Number>{tmp1};
}

TNode<Number> FromConstexpr_Number_constexpr_Smi_0(compiler::CodeAssemblerState* state_, Smi p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Number> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Number>{tmp1};
}

TNode<Smi> FromConstexpr_Smi_constexpr_Smi_0(compiler::CodeAssemblerState* state_, Smi p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Smi> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Smi>{tmp1};
}

TNode<Uint32T> FromConstexpr_uint32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Int32Constant(p_i);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Uint32T> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Uint32T>{tmp2};
}

TNode<UintPtrT> FromConstexpr_uintptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Uint32T> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_uint32_constexpr_int31_0(state_, p_i);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<UintPtrT> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<UintPtrT>{tmp2};
}

TNode<Float64T> FromConstexpr_float64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Float64T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Float64Constant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Float64T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Float64T>{tmp1};
}

TNode<Float64T> FromConstexpr_float64_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Float64T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Float64Constant(p_i);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Float64T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Float64T>{tmp1};
}

TNode<BoolT> FromConstexpr_bool_constexpr_bool_0(compiler::CodeAssemblerState* state_, bool p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).BoolConstant(p_b);
    ca_.Goto(&block2, tmp0);
  }

    TNode<BoolT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<BoolT>{tmp1};
}

TNode<Smi> FromConstexpr_LanguageMode_constexpr_LanguageMode_0(compiler::CodeAssemblerState* state_, LanguageMode p_m) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = ca_.SmiConstant(p_m);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Smi>{tmp0});
    ca_.Goto(&block2, tmp1);
  }

    TNode<Smi> tmp2;
    ca_.Bind(&block2, &tmp2);
  return TNode<Smi>{tmp2};
}

TNode<Int32T> FromConstexpr_ElementsKind_constexpr_ElementsKind_0(compiler::CodeAssemblerState* state_, ElementsKind p_e) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Int32Constant(p_e);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Int32T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Int32T>{tmp1};
}

TNode<Object> FromConstexpr_Object_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).StringConstant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Object> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Object>{tmp1};
}

TNode<Object> FromConstexpr_JSAny_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).StringConstant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Object> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Object>{tmp1};
}

TNode<IntPtrT> FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(compiler::CodeAssemblerState* state_, int32_t p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).IntPtrConstant(p_c);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ContextSlot_0(compiler::CodeAssemblerState* state_, int32_t p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).IntPtrConstant(p_c);
    ca_.Goto(&block2, tmp0);
  }

    TNode<IntPtrT> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<IntPtrT>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseState_constexpr_PromiseState_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = ca_.Int32Constant(p_s);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Int32T> tmp1;
    ca_.Bind(&block2, &tmp1);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> Convert_int32_ElementsKind_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_elementsKind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elementsKind);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ConvertElementsKindToInt(TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Int32T> tmp2;
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Int32T>{tmp3};
}

TNode<Number> Convert_Number_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToTagged(TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Int32T> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Number>{tmp3};
}

TNode<IntPtrT> Convert_intptr_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Int32T> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<IntPtrT>{tmp3};
}

TNode<IntPtrT> Convert_intptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<IntPtrT>{tmp4};
}

TNode<Smi> Convert_Smi_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Int32T> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Smi>{tmp3};
}

TNode<Number> Convert_Number_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUint32ToTagged(TNode<Uint32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Uint32T> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Number>{tmp3};
}

TNode<Smi> Convert_Smi_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Uint32T> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Smi>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Uint32T> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<UintPtrT>{tmp3};
}

TNode<IntPtrT> Convert_intptr_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint16T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint16T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<Uint16T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{tmp0});
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Uint16T> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<IntPtrT>{tmp4};
}

TNode<Int32T> Convert_int32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint8T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = Convert_uint32_uint8_0(state_, TNode<Uint8T>{tmp0});
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Uint8T> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Int32T>{tmp4};
}

TNode<Int32T> Convert_int32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint16T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint16T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint16T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = Convert_uint32_uint16_0(state_, TNode<Uint16T>{tmp0});
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Uint16T> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Int32T>{tmp4};
}

TNode<Int32T> Convert_int32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Uint32T> tmp1;
    USE(tmp1);
    tmp1 = Convert_uint32_uint31_0(state_, TNode<Uint32T>{tmp0});
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Uint32T> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Int32T>{tmp4};
}

TNode<Int32T> Convert_int32_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<IntPtrT> tmp2;
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Int32T>{tmp3};
}

TNode<Int32T> Convert_int32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Int32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_n);

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
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TruncateHeapNumberValueToWord32(TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp3)});
    ca_.Goto(&block1, tmp2, tmp5);
  }

  if (block4.is_used()) {
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Int32T> tmp10;
    USE(tmp10);
    tmp10 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp9});
    ca_.Goto(&block1, tmp6, tmp10);
  }

  if (block1.is_used()) {
    TNode<Number> tmp11;
    TNode<Int32T> tmp12;
    ca_.Bind(&block1, &tmp11, &tmp12);
    ca_.Goto(&block6, tmp11, tmp12);
  }

    TNode<Number> tmp13;
    TNode<Int32T> tmp14;
    ca_.Bind(&block6, &tmp13, &tmp14);
  return TNode<Int32T>{tmp14};
}

TNode<Smi> Convert_Smi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Smi>{tmp3};
}

TNode<Uint32T> Convert_uint32_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp0});
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp1});
    TNode<Uint32T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp2});
    ca_.Goto(&block2, tmp0, tmp3);
  }

    TNode<UintPtrT> tmp4;
    TNode<Uint32T> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
  return TNode<Uint32T>{tmp5};
}

TNode<IntPtrT> Convert_intptr_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_s);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<IntPtrT>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_ps) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ps);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp0});
    TNode<UintPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Smi> tmp3;
    TNode<UintPtrT> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<UintPtrT>{tmp4};
}

TNode<IntPtrT> Convert_intptr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp0});
    ca_.Goto(&block6, tmp0, tmp1);
  }

  if (block5.is_used()) {
    TNode<UintPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block5, &tmp2, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'i >= 0' failed", "src/builtins/convert.tq", 171);
  }

  if (block4.is_used()) {
    TNode<UintPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block4, &tmp4, &tmp5);
  }

    TNode<UintPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    ca_.Bind(&block6, &tmp6, &tmp7);
  return TNode<IntPtrT>{tmp7};
}

TNode<Smi> Convert_PositiveSmi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp0});
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = (TNode<Smi>{tmp1});
    ca_.Goto(&block6, tmp0, tmp2);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block5, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsValidPositiveSmi(i)' failed", "src/builtins/convert.tq", 175);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block4, &tmp4);
  }

    TNode<IntPtrT> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block6, &tmp5, &tmp6);
  return TNode<Smi>{tmp6};
}

TNode<Smi> Convert_PositiveSmi_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui, compiler::CodeAssemblerLabel* label_IfOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp0}, TNode<UintPtrT>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block3, &tmp3);
    ca_.Goto(label_IfOverflow);
  }

  if (block4.is_used()) {
    TNode<UintPtrT> tmp4;
    ca_.Bind(&block4, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp4});
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp5});
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = (TNode<Smi>{tmp6});
    ca_.Goto(&block5, tmp4, tmp7);
  }

    TNode<UintPtrT> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

TNode<Smi> Convert_PositiveSmi_intptr_1(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i, compiler::CodeAssemblerLabel* label_IfOverflow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp2;
    ca_.Bind(&block3, &tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp2});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = (TNode<Smi>{tmp3});
    ca_.Goto(&block6, tmp2, tmp4);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block4, &tmp5);
    ca_.Goto(label_IfOverflow);
  }

    TNode<IntPtrT> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block6, &tmp6, &tmp7);
  return TNode<Smi>{tmp7};
}

TNode<Int32T> Convert_int32_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_s);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Int32T>{tmp3};
}

TNode<Float64T> Convert_float64_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_h) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapNumber> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapNumber, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_h);

  if (block0.is_used()) {
    TNode<HeapNumber> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = LoadHeapNumberValue_0(state_, TNode<HeapNumber>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<HeapNumber> tmp2;
    TNode<Float64T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Float64T>{tmp3};
}

TNode<Float64T> Convert_float64_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_n);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Number> tmp2;
    TNode<Float64T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Float64T>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_n);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = ChangeUintPtrNumberToUintPtr_0(state_, TNode<Number>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Number> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<UintPtrT>{tmp3};
}

TNode<Float64T> Convert_float64_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float32T, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_f);

  if (block0.is_used()) {
    TNode<Float32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeFloat32ToFloat64(TNode<Float32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Float32T> tmp2;
    TNode<Float64T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Float64T>{tmp3};
}

TNode<Float32T> Convert_float32_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, Float32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_f);

  if (block0.is_used()) {
    TNode<Float64T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float32T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Float64T> tmp2;
    TNode<Float32T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Float32T>{tmp3};
}

TNode<Float32T> Convert_float32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Float32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_n);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number>{tmp0});
    TNode<Float32T> tmp2;
    USE(tmp2);
    tmp2 = Convert_float32_float64_0(state_, TNode<Float64T>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Number> tmp3;
    TNode<Float32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Float32T>{tmp4};
}

TNode<Number> Convert_Number_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_d);

  if (block0.is_used()) {
    TNode<Float64T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeFloat64ToTagged(TNode<Float64T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Number>{tmp3};
}

TNode<Float64T> Convert_float64_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUintPtrToFloat64(TNode<UintPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<UintPtrT> tmp2;
    TNode<Float64T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Float64T>{tmp3};
}

TNode<Number> Convert_Number_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_ui);

  if (block0.is_used()) {
    TNode<UintPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Number> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeUintPtrToTagged(TNode<UintPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<UintPtrT> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Number>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Float64T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Float64T, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_d);

  if (block0.is_used()) {
    TNode<Float64T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Float64T> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<UintPtrT>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<UintPtrT>{tmp3};
}

TNode<UintPtrT> Convert_uintptr_RawPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_r);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<UintPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Unsigned(TNode<RawPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<RawPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<UintPtrT>{tmp3};
}

TNode<IntPtrT> Convert_intptr_RawPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_r);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).Signed(TNode<RawPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<RawPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<IntPtrT>{tmp3};
}

TNode<BInt> Convert_bint_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, BInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_v);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp0});
    TNode<BInt> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrToBInt(TNode<IntPtrT>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Int32T> tmp3;
    TNode<BInt> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<BInt>{tmp4};
}

TNode<BInt> Convert_bint_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, BInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_v);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BInt> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IntPtrToBInt(TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<IntPtrT> tmp2;
    TNode<BInt> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BInt>{tmp3};
}

TNode<BInt> Convert_bint_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BInt> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_v);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BInt> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).SmiToBInt(TNode<Smi>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<BInt> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BInt>{tmp3};
}

TNode<Int32T> Convert_PromiseState_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_s) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_s);

  if (block0.is_used()) {
    TNode<Int32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Int32T> tmp2;
    TNode<Int32T> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Int32T>{tmp3};
}

TNode<Uint32T> Convert_uint32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint8T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint8T> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Uint8T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Uint32T>{tmp2};
}

TNode<Uint32T> Convert_uint32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint16T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint16T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint16T> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Uint16T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Uint32T>{tmp2};
}

TNode<Uint32T> Convert_uint32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Uint32T> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Uint32T>{tmp2};
}

}  // namespace internal
}  // namespace v8

