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

TNode<String> MakeDataViewGetterNameString_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getUint8");
    ca_.Goto(&block1, tmp0);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT8_ELEMENTS)))) {
      ca_.Goto(&block5);
    } else {
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    TNode<String> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getInt8");
    ca_.Goto(&block1, tmp1);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS)))) {
      ca_.Goto(&block8);
    } else {
      ca_.Goto(&block9);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getUint16");
    ca_.Goto(&block1, tmp2);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT16_ELEMENTS)))) {
      ca_.Goto(&block11);
    } else {
      ca_.Goto(&block12);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    TNode<String> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getInt16");
    ca_.Goto(&block1, tmp3);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT32_ELEMENTS)))) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getUint32");
    ca_.Goto(&block1, tmp4);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT32_ELEMENTS)))) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getInt32");
    ca_.Goto(&block1, tmp5);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT32_ELEMENTS)))) {
      ca_.Goto(&block20);
    } else {
      ca_.Goto(&block21);
    }
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getFloat32");
    ca_.Goto(&block1, tmp6);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT64_ELEMENTS)))) {
      ca_.Goto(&block23);
    } else {
      ca_.Goto(&block24);
    }
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getFloat64");
    ca_.Goto(&block1, tmp7);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGINT64_ELEMENTS)))) {
      ca_.Goto(&block26);
    } else {
      ca_.Goto(&block27);
    }
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getBigInt64");
    ca_.Goto(&block1, tmp8);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGUINT64_ELEMENTS)))) {
      ca_.Goto(&block29);
    } else {
      ca_.Goto(&block30);
    }
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.getBigUint64");
    ca_.Goto(&block1, tmp9);
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<String> tmp10;
    ca_.Bind(&block1, &tmp10);
    ca_.Goto(&block32, tmp10);
  }

    TNode<String> tmp11;
    ca_.Bind(&block32, &tmp11);
  return TNode<String>{tmp11};
}

TNode<String> MakeDataViewSetterNameString_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<String> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setUint8");
    ca_.Goto(&block1, tmp0);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT8_ELEMENTS)))) {
      ca_.Goto(&block5);
    } else {
      ca_.Goto(&block6);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    TNode<String> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setInt8");
    ca_.Goto(&block1, tmp1);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS)))) {
      ca_.Goto(&block8);
    } else {
      ca_.Goto(&block9);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setUint16");
    ca_.Goto(&block1, tmp2);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT16_ELEMENTS)))) {
      ca_.Goto(&block11);
    } else {
      ca_.Goto(&block12);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    TNode<String> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setInt16");
    ca_.Goto(&block1, tmp3);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT32_ELEMENTS)))) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setUint32");
    ca_.Goto(&block1, tmp4);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT32_ELEMENTS)))) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setInt32");
    ca_.Goto(&block1, tmp5);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT32_ELEMENTS)))) {
      ca_.Goto(&block20);
    } else {
      ca_.Goto(&block21);
    }
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setFloat32");
    ca_.Goto(&block1, tmp6);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT64_ELEMENTS)))) {
      ca_.Goto(&block23);
    } else {
      ca_.Goto(&block24);
    }
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setFloat64");
    ca_.Goto(&block1, tmp7);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGINT64_ELEMENTS)))) {
      ca_.Goto(&block26);
    } else {
      ca_.Goto(&block27);
    }
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setBigInt64");
    ca_.Goto(&block1, tmp8);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGUINT64_ELEMENTS)))) {
      ca_.Goto(&block29);
    } else {
      ca_.Goto(&block30);
    }
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "DataView.prototype.setBigUint64");
    ca_.Goto(&block1, tmp9);
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<String> tmp10;
    ca_.Bind(&block1, &tmp10);
    ca_.Goto(&block32, tmp10);
  }

    TNode<String> tmp11;
    ca_.Bind(&block32, &tmp11);
  return TNode<String>{tmp11};
}

TNode<BoolT> WasDetached_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_view) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBufferView> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBufferView, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_view);

  if (block0.is_used()) {
    TNode<JSArrayBufferView> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp1);
    TNode<JSArrayBuffer>tmp2 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp2});
    ca_.Goto(&block2, tmp0, tmp3);
  }

    TNode<JSArrayBufferView> tmp4;
    TNode<BoolT> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
  return TNode<BoolT>{tmp5};
}

TNode<JSDataView> ValidateDataView_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<String> p_method) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, Object, Context, JSDataView> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, JSDataView> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_method);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSDataView> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_JSDataView_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp1, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<String> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp4}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp6});
  }

  if (block4.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<String> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSDataView> tmp14;
    ca_.Bind(&block4, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp9, tmp10, tmp11, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<String> tmp17;
    TNode<JSDataView> tmp18;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17, &tmp18);
  return TNode<JSDataView>{tmp18};
}

TF_BUILTIN(DataViewPrototypeGetBuffer, CodeStubAssembler) {
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
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "get DataView.prototype.buffer");
    TNode<JSDataView> tmp6;
    USE(tmp6);
    tmp6 = ValidateDataView_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<String>{tmp5});
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp7);
    TNode<JSArrayBuffer>tmp8 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp6, tmp7});
    arguments.PopAndReturn(tmp8);
  }
}

TF_BUILTIN(DataViewPrototypeGetByteLength, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSDataView> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSDataView> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "get DataView.prototype.byte_length");
    TNode<JSDataView> tmp6;
    USE(tmp6);
    tmp6 = ValidateDataView_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<String>{tmp5});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = WasDetached_0(state_, TNode<JSArrayBufferView>{tmp6});
    ca_.Branch(tmp7, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<JSDataView> tmp13;
    ca_.Bind(&block1, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<Number> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    arguments.PopAndReturn(tmp14);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<JSDataView> tmp20;
    ca_.Bind(&block2, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<IntPtrT> tmp21 = ca_.IntPtrConstant(JSArrayBufferView::kByteLengthOffset);
    USE(tmp21);
    TNode<UintPtrT>tmp22 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp20, tmp21});
    TNode<Number> tmp23;
    USE(tmp23);
    tmp23 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp22});
    arguments.PopAndReturn(tmp23);
  }
}

TF_BUILTIN(DataViewPrototypeGetByteOffset, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSDataView> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSDataView> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, "get DataView.prototype.byte_offset");
    TNode<JSDataView> tmp6;
    USE(tmp6);
    tmp6 = ValidateDataView_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<String>{tmp5});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = WasDetached_0(state_, TNode<JSArrayBufferView>{tmp6});
    ca_.Branch(tmp7, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<JSDataView> tmp13;
    ca_.Bind(&block1, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<Number> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    arguments.PopAndReturn(tmp14);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<JSDataView> tmp20;
    ca_.Bind(&block2, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<IntPtrT> tmp21 = ca_.IntPtrConstant(JSArrayBufferView::kByteOffsetOffset);
    USE(tmp21);
    TNode<UintPtrT>tmp22 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp20, tmp21});
    TNode<Number> tmp23;
    USE(tmp23);
    tmp23 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp22});
    arguments.PopAndReturn(tmp23);
  }
}

TNode<Smi> LoadDataView8_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    if ((p_signed)) {
      ca_.Goto(&block2, tmp0, tmp1);
    } else {
      ca_.Goto(&block3, tmp0, tmp1);
    }
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp2;
    TNode<UintPtrT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp4);
    TNode<RawPtrT>tmp5 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp2, tmp4});
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = DataViewBuiltinsAssembler(state_).LoadInt8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp3});
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp6});
    ca_.Goto(&block1, tmp2, tmp3, tmp7);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp8;
    TNode<UintPtrT> tmp9;
    ca_.Bind(&block3, &tmp8, &tmp9);
    TNode<IntPtrT> tmp10 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp10);
    TNode<RawPtrT>tmp11 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp8, tmp10});
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp11}, TNode<UintPtrT>{tmp9});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = Convert_Smi_uint32_0(state_, TNode<Uint32T>{tmp12});
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<JSArrayBuffer> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block5, tmp14, tmp15, tmp16);
  }

    TNode<JSArrayBuffer> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19);
  return TNode<Smi>{tmp19};
}

TNode<Number> LoadDataView16_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Int32T, Int32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Int32T, Int32T, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Int32T, Int32T, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Int32T, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Int32T, Int32T, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp3);
    TNode<RawPtrT>tmp4 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp3});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1, tmp2, tmp4, ca_.Uninitialized<Int32T>(), ca_.Uninitialized<Int32T>(), ca_.Uninitialized<Int32T>());
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<BoolT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<Int32T> tmp9;
    TNode<Int32T> tmp10;
    TNode<Int32T> tmp11;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp8}, TNode<UintPtrT>{tmp6});
    TNode<Int32T> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp12});
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp14});
    TNode<Int32T> tmp16;
    USE(tmp16);
    tmp16 = DataViewBuiltinsAssembler(state_).LoadInt8(TNode<RawPtrT>{tmp8}, TNode<UintPtrT>{tmp15});
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<Int32T> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).Word32Shl(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp17});
    TNode<Int32T> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp18}, TNode<Int32T>{tmp13});
    ca_.Goto(&block4, tmp5, tmp6, tmp7, tmp8, tmp13, tmp16, tmp19);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<BoolT> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<Int32T> tmp24;
    TNode<Int32T> tmp25;
    TNode<Int32T> tmp26;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<Int32T> tmp27;
    USE(tmp27);
    tmp27 = DataViewBuiltinsAssembler(state_).LoadInt8(TNode<RawPtrT>{tmp23}, TNode<UintPtrT>{tmp21});
    TNode<UintPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp28});
    TNode<Uint32T> tmp30;
    USE(tmp30);
    tmp30 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp23}, TNode<UintPtrT>{tmp29});
    TNode<Int32T> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp30});
    TNode<Int32T> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<Int32T> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).Word32Shl(TNode<Int32T>{tmp27}, TNode<Int32T>{tmp32});
    TNode<Int32T> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp33}, TNode<Int32T>{tmp31});
    ca_.Goto(&block4, tmp20, tmp21, tmp22, tmp23, tmp27, tmp31, tmp34);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<BoolT> tmp37;
    TNode<RawPtrT> tmp38;
    TNode<Int32T> tmp39;
    TNode<Int32T> tmp40;
    TNode<Int32T> tmp41;
    ca_.Bind(&block4, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    if ((p_signed)) {
      ca_.Goto(&block5, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
    } else {
      ca_.Goto(&block6, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
    }
  }

  if (block5.is_used()) {
    TNode<JSArrayBuffer> tmp42;
    TNode<UintPtrT> tmp43;
    TNode<BoolT> tmp44;
    TNode<RawPtrT> tmp45;
    TNode<Int32T> tmp46;
    TNode<Int32T> tmp47;
    TNode<Int32T> tmp48;
    ca_.Bind(&block5, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<Smi> tmp49;
    USE(tmp49);
    tmp49 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp48});
    ca_.Goto(&block1, tmp42, tmp43, tmp44, tmp49);
  }

  if (block6.is_used()) {
    TNode<JSArrayBuffer> tmp50;
    TNode<UintPtrT> tmp51;
    TNode<BoolT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<Int32T> tmp54;
    TNode<Int32T> tmp55;
    TNode<Int32T> tmp56;
    ca_.Bind(&block6, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<Int32T> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_int32_constexpr_int31_0(state_, 0xFFFF);
    TNode<Int32T> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp56}, TNode<Int32T>{tmp57});
    TNode<Smi> tmp59;
    USE(tmp59);
    tmp59 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp58});
    ca_.Goto(&block1, tmp50, tmp51, tmp52, tmp59);
  }

  if (block1.is_used()) {
    TNode<JSArrayBuffer> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<BoolT> tmp62;
    TNode<Number> tmp63;
    ca_.Bind(&block1, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block8, tmp60, tmp61, tmp62, tmp63);
  }

    TNode<JSArrayBuffer> tmp64;
    TNode<UintPtrT> tmp65;
    TNode<BoolT> tmp66;
    TNode<Number> tmp67;
    ca_.Bind(&block8, &tmp64, &tmp65, &tmp66, &tmp67);
  return TNode<Number>{tmp67};
}

TNode<Number> LoadDataView32_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp3);
    TNode<RawPtrT>tmp4 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp3});
    TNode<Uint32T> tmp5;
    USE(tmp5);
    tmp5 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp1});
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp6});
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp9});
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp10});
    TNode<UintPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp12});
    TNode<Uint32T> tmp14;
    USE(tmp14);
    tmp14 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1, tmp2, tmp4, tmp5, tmp8, tmp11, tmp14, ca_.Uninitialized<Uint32T>());
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<BoolT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<Uint32T> tmp19;
    TNode<Uint32T> tmp20;
    TNode<Uint32T> tmp21;
    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    ca_.Bind(&block2, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<Uint32T> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp22}, TNode<Uint32T>{tmp24});
    TNode<Uint32T> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp21}, TNode<Uint32T>{tmp26});
    TNode<Uint32T> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp25}, TNode<Uint32T>{tmp27});
    TNode<Uint32T> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp20}, TNode<Uint32T>{tmp29});
    TNode<Uint32T> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp28}, TNode<Uint32T>{tmp30});
    TNode<Uint32T> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp31}, TNode<Uint32T>{tmp19});
    ca_.Goto(&block4, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp32);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<BoolT> tmp35;
    TNode<RawPtrT> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    ca_.Bind(&block3, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Uint32T> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp37}, TNode<Uint32T>{tmp42});
    TNode<Uint32T> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp38}, TNode<Uint32T>{tmp44});
    TNode<Uint32T> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp43}, TNode<Uint32T>{tmp45});
    TNode<Uint32T> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp39}, TNode<Uint32T>{tmp47});
    TNode<Uint32T> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp46}, TNode<Uint32T>{tmp48});
    TNode<Uint32T> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp49}, TNode<Uint32T>{tmp40});
    ca_.Goto(&block4, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp50);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp51;
    TNode<UintPtrT> tmp52;
    TNode<BoolT> tmp53;
    TNode<RawPtrT> tmp54;
    TNode<Uint32T> tmp55;
    TNode<Uint32T> tmp56;
    TNode<Uint32T> tmp57;
    TNode<Uint32T> tmp58;
    TNode<Uint32T> tmp59;
    ca_.Bind(&block4, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT32_ELEMENTS)))) {
      ca_.Goto(&block5, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59);
    } else {
      ca_.Goto(&block6, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59);
    }
  }

  if (block5.is_used()) {
    TNode<JSArrayBuffer> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<BoolT> tmp62;
    TNode<RawPtrT> tmp63;
    TNode<Uint32T> tmp64;
    TNode<Uint32T> tmp65;
    TNode<Uint32T> tmp66;
    TNode<Uint32T> tmp67;
    TNode<Uint32T> tmp68;
    ca_.Bind(&block5, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
    TNode<Int32T> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp68});
    TNode<Number> tmp70;
    USE(tmp70);
    tmp70 = Convert_Number_int32_0(state_, TNode<Int32T>{tmp69});
    ca_.Goto(&block1, tmp60, tmp61, tmp62, tmp70);
  }

  if (block6.is_used()) {
    TNode<JSArrayBuffer> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<BoolT> tmp73;
    TNode<RawPtrT> tmp74;
    TNode<Uint32T> tmp75;
    TNode<Uint32T> tmp76;
    TNode<Uint32T> tmp77;
    TNode<Uint32T> tmp78;
    TNode<Uint32T> tmp79;
    ca_.Bind(&block6, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT32_ELEMENTS)))) {
      ca_.Goto(&block8, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
    } else {
      ca_.Goto(&block9, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
    }
  }

  if (block8.is_used()) {
    TNode<JSArrayBuffer> tmp80;
    TNode<UintPtrT> tmp81;
    TNode<BoolT> tmp82;
    TNode<RawPtrT> tmp83;
    TNode<Uint32T> tmp84;
    TNode<Uint32T> tmp85;
    TNode<Uint32T> tmp86;
    TNode<Uint32T> tmp87;
    TNode<Uint32T> tmp88;
    ca_.Bind(&block8, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
    TNode<Number> tmp89;
    USE(tmp89);
    tmp89 = Convert_Number_uint32_0(state_, TNode<Uint32T>{tmp88});
    ca_.Goto(&block1, tmp80, tmp81, tmp82, tmp89);
  }

  if (block9.is_used()) {
    TNode<JSArrayBuffer> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<BoolT> tmp92;
    TNode<RawPtrT> tmp93;
    TNode<Uint32T> tmp94;
    TNode<Uint32T> tmp95;
    TNode<Uint32T> tmp96;
    TNode<Uint32T> tmp97;
    TNode<Uint32T> tmp98;
    ca_.Bind(&block9, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT32_ELEMENTS)))) {
      ca_.Goto(&block11, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
    } else {
      ca_.Goto(&block12, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
    }
  }

  if (block11.is_used()) {
    TNode<JSArrayBuffer> tmp99;
    TNode<UintPtrT> tmp100;
    TNode<BoolT> tmp101;
    TNode<RawPtrT> tmp102;
    TNode<Uint32T> tmp103;
    TNode<Uint32T> tmp104;
    TNode<Uint32T> tmp105;
    TNode<Uint32T> tmp106;
    TNode<Uint32T> tmp107;
    ca_.Bind(&block11, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    TNode<Float32T> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).BitcastInt32ToFloat32(TNode<Uint32T>{tmp107});
    TNode<Float64T> tmp109;
    USE(tmp109);
    tmp109 = Convert_float64_float32_0(state_, TNode<Float32T>{tmp108});
    TNode<Number> tmp110;
    USE(tmp110);
    tmp110 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp109});
    ca_.Goto(&block1, tmp99, tmp100, tmp101, tmp110);
  }

  if (block12.is_used()) {
    TNode<JSArrayBuffer> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<BoolT> tmp113;
    TNode<RawPtrT> tmp114;
    TNode<Uint32T> tmp115;
    TNode<Uint32T> tmp116;
    TNode<Uint32T> tmp117;
    TNode<Uint32T> tmp118;
    TNode<Uint32T> tmp119;
    ca_.Bind(&block12, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<JSArrayBuffer> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<BoolT> tmp122;
    TNode<Number> tmp123;
    ca_.Bind(&block1, &tmp120, &tmp121, &tmp122, &tmp123);
    ca_.Goto(&block14, tmp120, tmp121, tmp122, tmp123);
  }

    TNode<JSArrayBuffer> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<BoolT> tmp126;
    TNode<Number> tmp127;
    ca_.Bind(&block14, &tmp124, &tmp125, &tmp126, &tmp127);
  return TNode<Number>{tmp127};
}

TNode<Number> LoadDataViewFloat64_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BoolT, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp3);
    TNode<RawPtrT>tmp4 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp3});
    TNode<Uint32T> tmp5;
    USE(tmp5);
    tmp5 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp1});
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp6});
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp9});
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp10});
    TNode<UintPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp12});
    TNode<Uint32T> tmp14;
    USE(tmp14);
    tmp14 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp13});
    TNode<UintPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_uintptr_constexpr_int31_0(state_, 4);
    TNode<UintPtrT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp15});
    TNode<Uint32T> tmp17;
    USE(tmp17);
    tmp17 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp16});
    TNode<UintPtrT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_uintptr_constexpr_int31_0(state_, 5);
    TNode<UintPtrT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp18});
    TNode<Uint32T> tmp20;
    USE(tmp20);
    tmp20 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp19});
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_uintptr_constexpr_int31_0(state_, 6);
    TNode<UintPtrT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp21});
    TNode<Uint32T> tmp23;
    USE(tmp23);
    tmp23 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp22});
    TNode<UintPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_uintptr_constexpr_int31_0(state_, 7);
    TNode<UintPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp1}, TNode<UintPtrT>{tmp24});
    TNode<Uint32T> tmp26;
    USE(tmp26);
    tmp26 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp25});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1, tmp2, tmp4, tmp5, tmp8, tmp11, tmp14, tmp17, tmp20, tmp23, tmp26, ca_.Uninitialized<Uint32T>(), ca_.Uninitialized<Uint32T>());
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<BoolT> tmp29;
    TNode<RawPtrT> tmp30;
    TNode<Uint32T> tmp31;
    TNode<Uint32T> tmp32;
    TNode<Uint32T> tmp33;
    TNode<Uint32T> tmp34;
    TNode<Uint32T> tmp35;
    TNode<Uint32T> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    ca_.Bind(&block2, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<Uint32T> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp34}, TNode<Uint32T>{tmp41});
    TNode<Uint32T> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp33}, TNode<Uint32T>{tmp43});
    TNode<Uint32T> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp42}, TNode<Uint32T>{tmp44});
    TNode<Uint32T> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp32}, TNode<Uint32T>{tmp46});
    TNode<Uint32T> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp45}, TNode<Uint32T>{tmp47});
    TNode<Uint32T> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp48}, TNode<Uint32T>{tmp31});
    TNode<Uint32T> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp38}, TNode<Uint32T>{tmp50});
    TNode<Uint32T> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp37}, TNode<Uint32T>{tmp52});
    TNode<Uint32T> tmp54;
    USE(tmp54);
    tmp54 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp51}, TNode<Uint32T>{tmp53});
    TNode<Uint32T> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp36}, TNode<Uint32T>{tmp55});
    TNode<Uint32T> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp54}, TNode<Uint32T>{tmp56});
    TNode<Uint32T> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp57}, TNode<Uint32T>{tmp35});
    ca_.Goto(&block4, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp49, tmp58);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<BoolT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<Uint32T> tmp63;
    TNode<Uint32T> tmp64;
    TNode<Uint32T> tmp65;
    TNode<Uint32T> tmp66;
    TNode<Uint32T> tmp67;
    TNode<Uint32T> tmp68;
    TNode<Uint32T> tmp69;
    TNode<Uint32T> tmp70;
    TNode<Uint32T> tmp71;
    TNode<Uint32T> tmp72;
    ca_.Bind(&block3, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<Uint32T> tmp73;
    USE(tmp73);
    tmp73 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp74;
    USE(tmp74);
    tmp74 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp63}, TNode<Uint32T>{tmp73});
    TNode<Uint32T> tmp75;
    USE(tmp75);
    tmp75 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp64}, TNode<Uint32T>{tmp75});
    TNode<Uint32T> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp74}, TNode<Uint32T>{tmp76});
    TNode<Uint32T> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp65}, TNode<Uint32T>{tmp78});
    TNode<Uint32T> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp77}, TNode<Uint32T>{tmp79});
    TNode<Uint32T> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp80}, TNode<Uint32T>{tmp66});
    TNode<Uint32T> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp67}, TNode<Uint32T>{tmp82});
    TNode<Uint32T> tmp84;
    USE(tmp84);
    tmp84 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp85;
    USE(tmp85);
    tmp85 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp68}, TNode<Uint32T>{tmp84});
    TNode<Uint32T> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp83}, TNode<Uint32T>{tmp85});
    TNode<Uint32T> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp88;
    USE(tmp88);
    tmp88 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp69}, TNode<Uint32T>{tmp87});
    TNode<Uint32T> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp86}, TNode<Uint32T>{tmp88});
    TNode<Uint32T> tmp90;
    USE(tmp90);
    tmp90 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp89}, TNode<Uint32T>{tmp70});
    ca_.Goto(&block4, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp90, tmp81);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<BoolT> tmp93;
    TNode<RawPtrT> tmp94;
    TNode<Uint32T> tmp95;
    TNode<Uint32T> tmp96;
    TNode<Uint32T> tmp97;
    TNode<Uint32T> tmp98;
    TNode<Uint32T> tmp99;
    TNode<Uint32T> tmp100;
    TNode<Uint32T> tmp101;
    TNode<Uint32T> tmp102;
    TNode<Uint32T> tmp103;
    TNode<Uint32T> tmp104;
    ca_.Bind(&block4, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<Float64T> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<Float64T> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).Float64InsertLowWord32(TNode<Float64T>{tmp105}, TNode<Uint32T>{tmp103});
    TNode<Float64T> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).Float64InsertHighWord32(TNode<Float64T>{tmp106}, TNode<Uint32T>{tmp104});
    TNode<Number> tmp108;
    USE(tmp108);
    tmp108 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp107});
    ca_.Goto(&block5, tmp91, tmp92, tmp93, tmp108);
  }

    TNode<JSArrayBuffer> tmp109;
    TNode<UintPtrT> tmp110;
    TNode<BoolT> tmp111;
    TNode<Number> tmp112;
    ca_.Bind(&block5, &tmp109, &tmp110, &tmp111, &tmp112);
  return TNode<Number>{tmp112};
}

int31_t kZeroDigitBigInt_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 0;
}

int31_t kOneDigitBigInt_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 1;
}

int31_t kTwoDigitBigInt_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 2;
}

TNode<BigInt> MakeBigIntOn64Bit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, Uint32T, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, Uint32T, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, Uint32T, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, Uint32T, IntPtrT, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, Uint32T, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_lowWord, p_highWord);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Uint32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp1}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp4, &block4, &block5, tmp0, tmp1, tmp2, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp9});
    ca_.Goto(&block6, tmp5, tmp6, tmp7, tmp8, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp11;
    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block6.is_used()) {
    TNode<Context> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    ca_.Bind(&block6, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Branch(tmp20, &block2, &block3, tmp16, tmp17, tmp18);
  }

  if (block2.is_used()) {
    TNode<Context> tmp21;
    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    ca_.Bind(&block2, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, kZeroDigitBigInt_0(state_));
    TNode<BigInt> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).AllocateBigInt(TNode<IntPtrT>{tmp24});
    TNode<BigInt> tmp26;
    USE(tmp26);
    tmp26 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp25});
    ca_.Goto(&block1, tmp21, tmp22, tmp23, tmp26);
  }

  if (block3.is_used()) {
    TNode<Context> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Uint32T> tmp29;
    ca_.Bind(&block3, &tmp27, &tmp28, &tmp29);
    TNode<Uint32T> tmp30;
    USE(tmp30);
    tmp30 = kPositiveSign_0(state_);
    TNode<UintPtrT> tmp31;
    USE(tmp31);
    tmp31 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp29});
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp31});
    TNode<UintPtrT> tmp33;
    USE(tmp33);
    tmp33 = Convert_uintptr_uint32_0(state_, TNode<Uint32T>{tmp28});
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp33});
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).WordShl(TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp35});
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp34});
    if ((p_signed)) {
      ca_.Goto(&block7, tmp27, tmp28, tmp29, tmp30, tmp32, tmp34, tmp37);
    } else {
      ca_.Goto(&block8, tmp27, tmp28, tmp29, tmp30, tmp32, tmp34, tmp37);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    ca_.Bind(&block7, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<IntPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp45});
    ca_.Branch(tmp46, &block10, &block11, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44);
  }

  if (block10.is_used()) {
    TNode<Context> tmp47;
    TNode<Uint32T> tmp48;
    TNode<Uint32T> tmp49;
    TNode<Uint32T> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    ca_.Bind(&block10, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<Uint32T> tmp54;
    USE(tmp54);
    tmp54 = kNegativeSign_0(state_);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp55}, TNode<IntPtrT>{tmp53});
    ca_.Goto(&block11, tmp47, tmp48, tmp49, tmp54, tmp51, tmp52, tmp56);
  }

  if (block11.is_used()) {
    TNode<Context> tmp57;
    TNode<Uint32T> tmp58;
    TNode<Uint32T> tmp59;
    TNode<Uint32T> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    ca_.Bind(&block11, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block9, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block8.is_used()) {
    TNode<Context> tmp64;
    TNode<Uint32T> tmp65;
    TNode<Uint32T> tmp66;
    TNode<Uint32T> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    ca_.Bind(&block8, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    ca_.Goto(&block9, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70);
  }

  if (block9.is_used()) {
    TNode<Context> tmp71;
    TNode<Uint32T> tmp72;
    TNode<Uint32T> tmp73;
    TNode<Uint32T> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    ca_.Bind(&block9, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, kOneDigitBigInt_0(state_));
    TNode<BigInt> tmp79;
    USE(tmp79);
    tmp79 = AllocateEmptyBigInt_0(state_, TNode<Context>{tmp71}, TNode<Uint32T>{tmp74}, TNode<IntPtrT>{tmp78});
    TNode<UintPtrT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp77});
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreBigIntDigit(TNode<BigInt>{tmp79}, TNode<IntPtrT>{tmp81}, TNode<UintPtrT>{tmp80});
    TNode<BigInt> tmp82;
    USE(tmp82);
    tmp82 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp79});
    ca_.Goto(&block1, tmp71, tmp72, tmp73, tmp82);
  }

  if (block1.is_used()) {
    TNode<Context> tmp83;
    TNode<Uint32T> tmp84;
    TNode<Uint32T> tmp85;
    TNode<BigInt> tmp86;
    ca_.Bind(&block1, &tmp83, &tmp84, &tmp85, &tmp86);
    ca_.Goto(&block12, tmp83, tmp84, tmp85, tmp86);
  }

    TNode<Context> tmp87;
    TNode<Uint32T> tmp88;
    TNode<Uint32T> tmp89;
    TNode<BigInt> tmp90;
    ca_.Bind(&block12, &tmp87, &tmp88, &tmp89, &tmp90);
  return TNode<BigInt>{tmp90};
}

TNode<BigInt> MakeBigIntOn32Bit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T, BigInt> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T, BigInt> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T, BigInt> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T, BigInt> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BoolT, Uint32T, Int32T, Int32T, BigInt> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_lowWord, p_highWord);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Uint32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp1}, TNode<Uint32T>{tmp3});
    ca_.Branch(tmp4, &block4, &block5, tmp0, tmp1, tmp2, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp9});
    ca_.Goto(&block6, tmp5, tmp6, tmp7, tmp8, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp11;
    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block5, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block6.is_used()) {
    TNode<Context> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    ca_.Bind(&block6, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Branch(tmp20, &block2, &block3, tmp16, tmp17, tmp18);
  }

  if (block2.is_used()) {
    TNode<Context> tmp21;
    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    ca_.Bind(&block2, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, kZeroDigitBigInt_0(state_));
    TNode<BigInt> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).AllocateBigInt(TNode<IntPtrT>{tmp24});
    TNode<BigInt> tmp26;
    USE(tmp26);
    tmp26 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp25});
    ca_.Goto(&block1, tmp21, tmp22, tmp23, tmp26);
  }

  if (block3.is_used()) {
    TNode<Context> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Uint32T> tmp29;
    ca_.Bind(&block3, &tmp27, &tmp28, &tmp29);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<Uint32T> tmp31;
    USE(tmp31);
    tmp31 = kPositiveSign_0(state_);
    TNode<Int32T> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp28});
    TNode<Int32T> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp29});
    TNode<Uint32T> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp29}, TNode<Uint32T>{tmp34});
    ca_.Branch(tmp35, &block7, &block8, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

  if (block7.is_used()) {
    TNode<Context> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<BoolT> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Int32T> tmp41;
    TNode<Int32T> tmp42;
    ca_.Bind(&block7, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    if ((p_signed)) {
      ca_.Goto(&block9, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
    } else {
      ca_.Goto(&block10, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp43;
    TNode<Uint32T> tmp44;
    TNode<Uint32T> tmp45;
    TNode<BoolT> tmp46;
    TNode<Uint32T> tmp47;
    TNode<Int32T> tmp48;
    TNode<Int32T> tmp49;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Int32T> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{tmp49}, TNode<Int32T>{tmp50});
    ca_.Branch(tmp51, &block12, &block13, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block12.is_used()) {
    TNode<Context> tmp52;
    TNode<Uint32T> tmp53;
    TNode<Uint32T> tmp54;
    TNode<BoolT> tmp55;
    TNode<Uint32T> tmp56;
    TNode<Int32T> tmp57;
    TNode<Int32T> tmp58;
    ca_.Bind(&block12, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<Uint32T> tmp59;
    USE(tmp59);
    tmp59 = kNegativeSign_0(state_);
    TNode<Int32T> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Int32T> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp60}, TNode<Int32T>{tmp58});
    TNode<Int32T> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp63;
    USE(tmp63);
    tmp63 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp57}, TNode<Int32T>{tmp62});
    ca_.Branch(tmp63, &block15, &block16, tmp52, tmp53, tmp54, tmp55, tmp59, tmp57, tmp61);
  }

  if (block15.is_used()) {
    TNode<Context> tmp64;
    TNode<Uint32T> tmp65;
    TNode<Uint32T> tmp66;
    TNode<BoolT> tmp67;
    TNode<Uint32T> tmp68;
    TNode<Int32T> tmp69;
    TNode<Int32T> tmp70;
    ca_.Bind(&block15, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<Int32T> tmp71;
    USE(tmp71);
    tmp71 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp70}, TNode<Int32T>{tmp71});
    ca_.Goto(&block16, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp72);
  }

  if (block16.is_used()) {
    TNode<Context> tmp73;
    TNode<Uint32T> tmp74;
    TNode<Uint32T> tmp75;
    TNode<BoolT> tmp76;
    TNode<Uint32T> tmp77;
    TNode<Int32T> tmp78;
    TNode<Int32T> tmp79;
    ca_.Bind(&block16, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    TNode<Int32T> tmp80;
    USE(tmp80);
    tmp80 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Int32T> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp80}, TNode<Int32T>{tmp78});
    TNode<Int32T> tmp82;
    USE(tmp82);
    tmp82 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp79}, TNode<Int32T>{tmp82});
    ca_.Branch(tmp83, &block17, &block18, tmp73, tmp74, tmp75, tmp76, tmp77, tmp81, tmp79);
  }

  if (block17.is_used()) {
    TNode<Context> tmp84;
    TNode<Uint32T> tmp85;
    TNode<Uint32T> tmp86;
    TNode<BoolT> tmp87;
    TNode<Uint32T> tmp88;
    TNode<Int32T> tmp89;
    TNode<Int32T> tmp90;
    ca_.Bind(&block17, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<BoolT> tmp91;
    USE(tmp91);
    tmp91 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block18, tmp84, tmp85, tmp86, tmp91, tmp88, tmp89, tmp90);
  }

  if (block18.is_used()) {
    TNode<Context> tmp92;
    TNode<Uint32T> tmp93;
    TNode<Uint32T> tmp94;
    TNode<BoolT> tmp95;
    TNode<Uint32T> tmp96;
    TNode<Int32T> tmp97;
    TNode<Int32T> tmp98;
    ca_.Bind(&block18, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    ca_.Goto(&block14, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
  }

  if (block13.is_used()) {
    TNode<Context> tmp99;
    TNode<Uint32T> tmp100;
    TNode<Uint32T> tmp101;
    TNode<BoolT> tmp102;
    TNode<Uint32T> tmp103;
    TNode<Int32T> tmp104;
    TNode<Int32T> tmp105;
    ca_.Bind(&block13, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
    TNode<BoolT> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block14, tmp99, tmp100, tmp101, tmp106, tmp103, tmp104, tmp105);
  }

  if (block14.is_used()) {
    TNode<Context> tmp107;
    TNode<Uint32T> tmp108;
    TNode<Uint32T> tmp109;
    TNode<BoolT> tmp110;
    TNode<Uint32T> tmp111;
    TNode<Int32T> tmp112;
    TNode<Int32T> tmp113;
    ca_.Bind(&block14, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    ca_.Goto(&block11, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113);
  }

  if (block10.is_used()) {
    TNode<Context> tmp114;
    TNode<Uint32T> tmp115;
    TNode<Uint32T> tmp116;
    TNode<BoolT> tmp117;
    TNode<Uint32T> tmp118;
    TNode<Int32T> tmp119;
    TNode<Int32T> tmp120;
    ca_.Bind(&block10, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120);
    TNode<BoolT> tmp121;
    USE(tmp121);
    tmp121 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp114, tmp115, tmp116, tmp121, tmp118, tmp119, tmp120);
  }

  if (block11.is_used()) {
    TNode<Context> tmp122;
    TNode<Uint32T> tmp123;
    TNode<Uint32T> tmp124;
    TNode<BoolT> tmp125;
    TNode<Uint32T> tmp126;
    TNode<Int32T> tmp127;
    TNode<Int32T> tmp128;
    ca_.Bind(&block11, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    ca_.Goto(&block8, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128);
  }

  if (block8.is_used()) {
    TNode<Context> tmp129;
    TNode<Uint32T> tmp130;
    TNode<Uint32T> tmp131;
    TNode<BoolT> tmp132;
    TNode<Uint32T> tmp133;
    TNode<Int32T> tmp134;
    TNode<Int32T> tmp135;
    ca_.Bind(&block8, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    ca_.Branch(tmp132, &block19, &block20, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, ca_.Uninitialized<BigInt>());
  }

  if (block19.is_used()) {
    TNode<Context> tmp136;
    TNode<Uint32T> tmp137;
    TNode<Uint32T> tmp138;
    TNode<BoolT> tmp139;
    TNode<Uint32T> tmp140;
    TNode<Int32T> tmp141;
    TNode<Int32T> tmp142;
    TNode<BigInt> tmp143;
    ca_.Bind(&block19, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
    TNode<IntPtrT> tmp144;
    USE(tmp144);
    tmp144 = FromConstexpr_intptr_constexpr_int31_0(state_, kTwoDigitBigInt_0(state_));
    TNode<BigInt> tmp145;
    USE(tmp145);
    tmp145 = AllocateEmptyBigInt_0(state_, TNode<Context>{tmp136}, TNode<Uint32T>{tmp140}, TNode<IntPtrT>{tmp144});
    ca_.Goto(&block21, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp145);
  }

  if (block20.is_used()) {
    TNode<Context> tmp146;
    TNode<Uint32T> tmp147;
    TNode<Uint32T> tmp148;
    TNode<BoolT> tmp149;
    TNode<Uint32T> tmp150;
    TNode<Int32T> tmp151;
    TNode<Int32T> tmp152;
    TNode<BigInt> tmp153;
    ca_.Bind(&block20, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153);
    TNode<IntPtrT> tmp154;
    USE(tmp154);
    tmp154 = FromConstexpr_intptr_constexpr_int31_0(state_, kOneDigitBigInt_0(state_));
    TNode<BigInt> tmp155;
    USE(tmp155);
    tmp155 = AllocateEmptyBigInt_0(state_, TNode<Context>{tmp146}, TNode<Uint32T>{tmp150}, TNode<IntPtrT>{tmp154});
    ca_.Goto(&block21, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp155);
  }

  if (block21.is_used()) {
    TNode<Context> tmp156;
    TNode<Uint32T> tmp157;
    TNode<Uint32T> tmp158;
    TNode<BoolT> tmp159;
    TNode<Uint32T> tmp160;
    TNode<Int32T> tmp161;
    TNode<Int32T> tmp162;
    TNode<BigInt> tmp163;
    ca_.Bind(&block21, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    TNode<IntPtrT> tmp164;
    USE(tmp164);
    tmp164 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp161});
    TNode<UintPtrT> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp164});
    TNode<IntPtrT> tmp166;
    USE(tmp166);
    tmp166 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreBigIntDigit(TNode<BigInt>{tmp163}, TNode<IntPtrT>{tmp166}, TNode<UintPtrT>{tmp165});
    ca_.Branch(tmp159, &block22, &block23, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163);
  }

  if (block22.is_used()) {
    TNode<Context> tmp167;
    TNode<Uint32T> tmp168;
    TNode<Uint32T> tmp169;
    TNode<BoolT> tmp170;
    TNode<Uint32T> tmp171;
    TNode<Int32T> tmp172;
    TNode<Int32T> tmp173;
    TNode<BigInt> tmp174;
    ca_.Bind(&block22, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp173});
    TNode<UintPtrT> tmp176;
    USE(tmp176);
    tmp176 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp175});
    TNode<IntPtrT> tmp177;
    USE(tmp177);
    tmp177 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    CodeStubAssembler(state_).StoreBigIntDigit(TNode<BigInt>{tmp174}, TNode<IntPtrT>{tmp177}, TNode<UintPtrT>{tmp176});
    ca_.Goto(&block23, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174);
  }

  if (block23.is_used()) {
    TNode<Context> tmp178;
    TNode<Uint32T> tmp179;
    TNode<Uint32T> tmp180;
    TNode<BoolT> tmp181;
    TNode<Uint32T> tmp182;
    TNode<Int32T> tmp183;
    TNode<Int32T> tmp184;
    TNode<BigInt> tmp185;
    ca_.Bind(&block23, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185);
    TNode<BigInt> tmp186;
    USE(tmp186);
    tmp186 = Convert_BigInt_MutableBigInt_0(state_, TNode<BigInt>{tmp185});
    ca_.Goto(&block1, tmp178, tmp179, tmp180, tmp186);
  }

  if (block1.is_used()) {
    TNode<Context> tmp187;
    TNode<Uint32T> tmp188;
    TNode<Uint32T> tmp189;
    TNode<BigInt> tmp190;
    ca_.Bind(&block1, &tmp187, &tmp188, &tmp189, &tmp190);
    ca_.Goto(&block24, tmp187, tmp188, tmp189, tmp190);
  }

    TNode<Context> tmp191;
    TNode<Uint32T> tmp192;
    TNode<Uint32T> tmp193;
    TNode<BigInt> tmp194;
    ca_.Bind(&block24, &tmp191, &tmp192, &tmp193, &tmp194);
  return TNode<BigInt>{tmp194};
}

TNode<BigInt> MakeBigInt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Uint32T, Uint32T, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_lowWord, p_highWord);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block2, tmp0, tmp1, tmp2);
    } else {
      ca_.Goto(&block3, tmp0, tmp1, tmp2);
    }
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
    TNode<BigInt> tmp6;
    USE(tmp6);
    tmp6 = MakeBigIntOn64Bit_0(state_, TNode<Context>{tmp3}, TNode<Uint32T>{tmp4}, TNode<Uint32T>{tmp5}, p_signed);
    ca_.Goto(&block1, tmp3, tmp4, tmp5, tmp6);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<Uint32T> tmp8;
    TNode<Uint32T> tmp9;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9);
    TNode<BigInt> tmp10;
    USE(tmp10);
    tmp10 = MakeBigIntOn32Bit_0(state_, TNode<Context>{tmp7}, TNode<Uint32T>{tmp8}, TNode<Uint32T>{tmp9}, p_signed);
    ca_.Goto(&block1, tmp7, tmp8, tmp9, tmp10);
  }

  if (block1.is_used()) {
    TNode<Context> tmp11;
    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<BigInt> tmp14;
    ca_.Bind(&block1, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block5, tmp11, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Uint32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<BigInt> tmp18;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18);
  return TNode<BigInt>{tmp18};
}

TNode<BigInt> LoadDataViewBigInt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, bool p_signed) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArrayBuffer, UintPtrT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArrayBuffer, UintPtrT, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArrayBuffer, UintPtrT, BoolT, BigInt> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_buffer, p_offset, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArrayBuffer> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp4);
    TNode<RawPtrT>tmp5 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp2});
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp7});
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp8});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp10});
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp11});
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp13});
    TNode<Uint32T> tmp15;
    USE(tmp15);
    tmp15 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp14});
    TNode<UintPtrT> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_uintptr_constexpr_int31_0(state_, 4);
    TNode<UintPtrT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp16});
    TNode<Uint32T> tmp18;
    USE(tmp18);
    tmp18 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp17});
    TNode<UintPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_uintptr_constexpr_int31_0(state_, 5);
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp19});
    TNode<Uint32T> tmp21;
    USE(tmp21);
    tmp21 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp20});
    TNode<UintPtrT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_uintptr_constexpr_int31_0(state_, 6);
    TNode<UintPtrT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp22});
    TNode<Uint32T> tmp24;
    USE(tmp24);
    tmp24 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp23});
    TNode<UintPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_uintptr_constexpr_int31_0(state_, 7);
    TNode<UintPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp25});
    TNode<Uint32T> tmp27;
    USE(tmp27);
    tmp27 = DataViewBuiltinsAssembler(state_).LoadUint8(TNode<RawPtrT>{tmp5}, TNode<UintPtrT>{tmp26});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp6, tmp9, tmp12, tmp15, tmp18, tmp21, tmp24, tmp27, ca_.Uninitialized<Uint32T>(), ca_.Uninitialized<Uint32T>());
  }

  if (block2.is_used()) {
    TNode<Context> tmp28;
    TNode<JSArrayBuffer> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<BoolT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<Uint32T> tmp33;
    TNode<Uint32T> tmp34;
    TNode<Uint32T> tmp35;
    TNode<Uint32T> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    TNode<Uint32T> tmp42;
    ca_.Bind(&block2, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<Uint32T> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp36}, TNode<Uint32T>{tmp43});
    TNode<Uint32T> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp35}, TNode<Uint32T>{tmp45});
    TNode<Uint32T> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp44}, TNode<Uint32T>{tmp46});
    TNode<Uint32T> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp34}, TNode<Uint32T>{tmp48});
    TNode<Uint32T> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp47}, TNode<Uint32T>{tmp49});
    TNode<Uint32T> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp50}, TNode<Uint32T>{tmp33});
    TNode<Uint32T> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp40}, TNode<Uint32T>{tmp52});
    TNode<Uint32T> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp39}, TNode<Uint32T>{tmp54});
    TNode<Uint32T> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp53}, TNode<Uint32T>{tmp55});
    TNode<Uint32T> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp38}, TNode<Uint32T>{tmp57});
    TNode<Uint32T> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp56}, TNode<Uint32T>{tmp58});
    TNode<Uint32T> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp59}, TNode<Uint32T>{tmp37});
    ca_.Goto(&block4, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp51, tmp60);
  }

  if (block3.is_used()) {
    TNode<Context> tmp61;
    TNode<JSArrayBuffer> tmp62;
    TNode<UintPtrT> tmp63;
    TNode<BoolT> tmp64;
    TNode<RawPtrT> tmp65;
    TNode<Uint32T> tmp66;
    TNode<Uint32T> tmp67;
    TNode<Uint32T> tmp68;
    TNode<Uint32T> tmp69;
    TNode<Uint32T> tmp70;
    TNode<Uint32T> tmp71;
    TNode<Uint32T> tmp72;
    TNode<Uint32T> tmp73;
    TNode<Uint32T> tmp74;
    TNode<Uint32T> tmp75;
    ca_.Bind(&block3, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<Uint32T> tmp76;
    USE(tmp76);
    tmp76 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp66}, TNode<Uint32T>{tmp76});
    TNode<Uint32T> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp67}, TNode<Uint32T>{tmp78});
    TNode<Uint32T> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp77}, TNode<Uint32T>{tmp79});
    TNode<Uint32T> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp68}, TNode<Uint32T>{tmp81});
    TNode<Uint32T> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp80}, TNode<Uint32T>{tmp82});
    TNode<Uint32T> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp83}, TNode<Uint32T>{tmp69});
    TNode<Uint32T> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp70}, TNode<Uint32T>{tmp85});
    TNode<Uint32T> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp88;
    USE(tmp88);
    tmp88 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp71}, TNode<Uint32T>{tmp87});
    TNode<Uint32T> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp86}, TNode<Uint32T>{tmp88});
    TNode<Uint32T> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T>{tmp72}, TNode<Uint32T>{tmp90});
    TNode<Uint32T> tmp92;
    USE(tmp92);
    tmp92 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp89}, TNode<Uint32T>{tmp91});
    TNode<Uint32T> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T>{tmp92}, TNode<Uint32T>{tmp73});
    ca_.Goto(&block4, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp93, tmp84);
  }

  if (block4.is_used()) {
    TNode<Context> tmp94;
    TNode<JSArrayBuffer> tmp95;
    TNode<UintPtrT> tmp96;
    TNode<BoolT> tmp97;
    TNode<RawPtrT> tmp98;
    TNode<Uint32T> tmp99;
    TNode<Uint32T> tmp100;
    TNode<Uint32T> tmp101;
    TNode<Uint32T> tmp102;
    TNode<Uint32T> tmp103;
    TNode<Uint32T> tmp104;
    TNode<Uint32T> tmp105;
    TNode<Uint32T> tmp106;
    TNode<Uint32T> tmp107;
    TNode<Uint32T> tmp108;
    ca_.Bind(&block4, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<BigInt> tmp109;
    USE(tmp109);
    tmp109 = MakeBigInt_0(state_, TNode<Context>{tmp94}, TNode<Uint32T>{tmp107}, TNode<Uint32T>{tmp108}, p_signed);
    ca_.Goto(&block5, tmp94, tmp95, tmp96, tmp97, tmp109);
  }

    TNode<Context> tmp110;
    TNode<JSArrayBuffer> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<BoolT> tmp113;
    TNode<BigInt> tmp114;
    ca_.Bind(&block5, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
  return TNode<BigInt>{tmp114};
}

TNode<Numeric> DataViewGet_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_requestIndex, TNode<Object> p_requestedLittleEndian, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, Object, Context, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, JSDataView> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Numeric> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Numeric> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_requestIndex, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = MakeDataViewGetterNameString_0(state_, p_kind);
    TNode<JSDataView> tmp5;
    USE(tmp5);
    tmp5 = ValidateDataView_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp4});
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = ToIndex_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<JSDataView> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block4.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<JSDataView> tmp18;
    TNode<Object> tmp19;
    TNode<Context> tmp20;
    TNode<UintPtrT> tmp21;
    ca_.Bind(&block4, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = ToBoolean_0(state_, TNode<Object>{tmp17});
    TNode<IntPtrT> tmp23 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp23);
    TNode<JSArrayBuffer>tmp24 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp18, tmp23});
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp24});
    ca_.Branch(tmp25, &block6, &block7, tmp14, tmp15, tmp16, tmp17, tmp18, tmp21, tmp22, tmp24);
  }

  if (block6.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<JSDataView> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<BoolT> tmp32;
    TNode<JSArrayBuffer> tmp33;
    ca_.Bind(&block6, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<String> tmp34;
    USE(tmp34);
    tmp34 = MakeDataViewGetterNameString_0(state_, p_kind);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp26}, MessageTemplate::kDetachedOperation, TNode<Object>{tmp34});
  }

  if (block7.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<JSDataView> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<BoolT> tmp41;
    TNode<JSArrayBuffer> tmp42;
    ca_.Bind(&block7, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<IntPtrT> tmp43 = ca_.IntPtrConstant(JSArrayBufferView::kByteOffsetOffset);
    USE(tmp43);
    TNode<UintPtrT>tmp44 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp39, tmp43});
    TNode<IntPtrT> tmp45 = ca_.IntPtrConstant(JSArrayBufferView::kByteLengthOffset);
    USE(tmp45);
    TNode<UintPtrT>tmp46 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp39, tmp45});
    TNode<UintPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_uintptr_constexpr_int31_0(state_, (DataViewBuiltinsAssembler(state_).DataViewElementSize(p_kind)));
    compiler::CodeAssemblerLabel label0(&ca_);
    CheckIntegerIndexAdditionOverflow_0(state_, TNode<UintPtrT>{tmp40}, TNode<UintPtrT>{tmp47}, TNode<UintPtrT>{tmp46}, &label0);
    ca_.Goto(&block8, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp44, tmp46, tmp47, tmp40, tmp47, tmp46);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp44, tmp46, tmp47, tmp40, tmp47, tmp46);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<JSDataView> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<BoolT> tmp54;
    TNode<JSArrayBuffer> tmp55;
    TNode<UintPtrT> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<UintPtrT> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<UintPtrT> tmp61;
    ca_.Bind(&block9, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block3, tmp48, tmp49, tmp50, tmp51, tmp52);
  }

  if (block8.is_used()) {
    TNode<Context> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<JSDataView> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<BoolT> tmp68;
    TNode<JSArrayBuffer> tmp69;
    TNode<UintPtrT> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<UintPtrT> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<UintPtrT> tmp75;
    ca_.Bind(&block8, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<UintPtrT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp67}, TNode<UintPtrT>{tmp70});
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)))) {
      ca_.Goto(&block10, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp76);
    } else {
      ca_.Goto(&block11, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp76);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<JSDataView> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<BoolT> tmp83;
    TNode<JSArrayBuffer> tmp84;
    TNode<UintPtrT> tmp85;
    TNode<UintPtrT> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<UintPtrT> tmp88;
    ca_.Bind(&block10, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
    TNode<Smi> tmp89;
    USE(tmp89);
    tmp89 = LoadDataView8_0(state_, TNode<JSArrayBuffer>{tmp84}, TNode<UintPtrT>{tmp88}, false);
    ca_.Goto(&block1, tmp77, tmp78, tmp79, tmp80, tmp89);
  }

  if (block11.is_used()) {
    TNode<Context> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    TNode<Object> tmp93;
    TNode<JSDataView> tmp94;
    TNode<UintPtrT> tmp95;
    TNode<BoolT> tmp96;
    TNode<JSArrayBuffer> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    TNode<UintPtrT> tmp101;
    ca_.Bind(&block11, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT8_ELEMENTS)))) {
      ca_.Goto(&block13, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
    } else {
      ca_.Goto(&block14, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
    }
  }

  if (block13.is_used()) {
    TNode<Context> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp105;
    TNode<JSDataView> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<BoolT> tmp108;
    TNode<JSArrayBuffer> tmp109;
    TNode<UintPtrT> tmp110;
    TNode<UintPtrT> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<UintPtrT> tmp113;
    ca_.Bind(&block13, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    TNode<Smi> tmp114;
    USE(tmp114);
    tmp114 = LoadDataView8_0(state_, TNode<JSArrayBuffer>{tmp109}, TNode<UintPtrT>{tmp113}, true);
    ca_.Goto(&block1, tmp102, tmp103, tmp104, tmp105, tmp114);
  }

  if (block14.is_used()) {
    TNode<Context> tmp115;
    TNode<Object> tmp116;
    TNode<Object> tmp117;
    TNode<Object> tmp118;
    TNode<JSDataView> tmp119;
    TNode<UintPtrT> tmp120;
    TNode<BoolT> tmp121;
    TNode<JSArrayBuffer> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<UintPtrT> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<UintPtrT> tmp126;
    ca_.Bind(&block14, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS)))) {
      ca_.Goto(&block16, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126);
    } else {
      ca_.Goto(&block17, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp127;
    TNode<Object> tmp128;
    TNode<Object> tmp129;
    TNode<Object> tmp130;
    TNode<JSDataView> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<BoolT> tmp133;
    TNode<JSArrayBuffer> tmp134;
    TNode<UintPtrT> tmp135;
    TNode<UintPtrT> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<UintPtrT> tmp138;
    ca_.Bind(&block16, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    TNode<Number> tmp139;
    USE(tmp139);
    tmp139 = LoadDataView16_0(state_, TNode<JSArrayBuffer>{tmp134}, TNode<UintPtrT>{tmp138}, TNode<BoolT>{tmp133}, false);
    ca_.Goto(&block1, tmp127, tmp128, tmp129, tmp130, tmp139);
  }

  if (block17.is_used()) {
    TNode<Context> tmp140;
    TNode<Object> tmp141;
    TNode<Object> tmp142;
    TNode<Object> tmp143;
    TNode<JSDataView> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<BoolT> tmp146;
    TNode<JSArrayBuffer> tmp147;
    TNode<UintPtrT> tmp148;
    TNode<UintPtrT> tmp149;
    TNode<UintPtrT> tmp150;
    TNode<UintPtrT> tmp151;
    ca_.Bind(&block17, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT16_ELEMENTS)))) {
      ca_.Goto(&block19, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151);
    } else {
      ca_.Goto(&block20, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151);
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<JSDataView> tmp156;
    TNode<UintPtrT> tmp157;
    TNode<BoolT> tmp158;
    TNode<JSArrayBuffer> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<UintPtrT> tmp161;
    TNode<UintPtrT> tmp162;
    TNode<UintPtrT> tmp163;
    ca_.Bind(&block19, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    TNode<Number> tmp164;
    USE(tmp164);
    tmp164 = LoadDataView16_0(state_, TNode<JSArrayBuffer>{tmp159}, TNode<UintPtrT>{tmp163}, TNode<BoolT>{tmp158}, true);
    ca_.Goto(&block1, tmp152, tmp153, tmp154, tmp155, tmp164);
  }

  if (block20.is_used()) {
    TNode<Context> tmp165;
    TNode<Object> tmp166;
    TNode<Object> tmp167;
    TNode<Object> tmp168;
    TNode<JSDataView> tmp169;
    TNode<UintPtrT> tmp170;
    TNode<BoolT> tmp171;
    TNode<JSArrayBuffer> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<UintPtrT> tmp175;
    TNode<UintPtrT> tmp176;
    ca_.Bind(&block20, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT32_ELEMENTS)))) {
      ca_.Goto(&block22, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
    } else {
      ca_.Goto(&block23, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
    }
  }

  if (block22.is_used()) {
    TNode<Context> tmp177;
    TNode<Object> tmp178;
    TNode<Object> tmp179;
    TNode<Object> tmp180;
    TNode<JSDataView> tmp181;
    TNode<UintPtrT> tmp182;
    TNode<BoolT> tmp183;
    TNode<JSArrayBuffer> tmp184;
    TNode<UintPtrT> tmp185;
    TNode<UintPtrT> tmp186;
    TNode<UintPtrT> tmp187;
    TNode<UintPtrT> tmp188;
    ca_.Bind(&block22, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
    TNode<Number> tmp189;
    USE(tmp189);
    tmp189 = LoadDataView32_0(state_, TNode<JSArrayBuffer>{tmp184}, TNode<UintPtrT>{tmp188}, TNode<BoolT>{tmp183}, p_kind);
    ca_.Goto(&block1, tmp177, tmp178, tmp179, tmp180, tmp189);
  }

  if (block23.is_used()) {
    TNode<Context> tmp190;
    TNode<Object> tmp191;
    TNode<Object> tmp192;
    TNode<Object> tmp193;
    TNode<JSDataView> tmp194;
    TNode<UintPtrT> tmp195;
    TNode<BoolT> tmp196;
    TNode<JSArrayBuffer> tmp197;
    TNode<UintPtrT> tmp198;
    TNode<UintPtrT> tmp199;
    TNode<UintPtrT> tmp200;
    TNode<UintPtrT> tmp201;
    ca_.Bind(&block23, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT32_ELEMENTS)))) {
      ca_.Goto(&block25, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201);
    } else {
      ca_.Goto(&block26, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201);
    }
  }

  if (block25.is_used()) {
    TNode<Context> tmp202;
    TNode<Object> tmp203;
    TNode<Object> tmp204;
    TNode<Object> tmp205;
    TNode<JSDataView> tmp206;
    TNode<UintPtrT> tmp207;
    TNode<BoolT> tmp208;
    TNode<JSArrayBuffer> tmp209;
    TNode<UintPtrT> tmp210;
    TNode<UintPtrT> tmp211;
    TNode<UintPtrT> tmp212;
    TNode<UintPtrT> tmp213;
    ca_.Bind(&block25, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213);
    TNode<Number> tmp214;
    USE(tmp214);
    tmp214 = LoadDataView32_0(state_, TNode<JSArrayBuffer>{tmp209}, TNode<UintPtrT>{tmp213}, TNode<BoolT>{tmp208}, p_kind);
    ca_.Goto(&block1, tmp202, tmp203, tmp204, tmp205, tmp214);
  }

  if (block26.is_used()) {
    TNode<Context> tmp215;
    TNode<Object> tmp216;
    TNode<Object> tmp217;
    TNode<Object> tmp218;
    TNode<JSDataView> tmp219;
    TNode<UintPtrT> tmp220;
    TNode<BoolT> tmp221;
    TNode<JSArrayBuffer> tmp222;
    TNode<UintPtrT> tmp223;
    TNode<UintPtrT> tmp224;
    TNode<UintPtrT> tmp225;
    TNode<UintPtrT> tmp226;
    ca_.Bind(&block26, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT32_ELEMENTS)))) {
      ca_.Goto(&block28, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226);
    } else {
      ca_.Goto(&block29, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226);
    }
  }

  if (block28.is_used()) {
    TNode<Context> tmp227;
    TNode<Object> tmp228;
    TNode<Object> tmp229;
    TNode<Object> tmp230;
    TNode<JSDataView> tmp231;
    TNode<UintPtrT> tmp232;
    TNode<BoolT> tmp233;
    TNode<JSArrayBuffer> tmp234;
    TNode<UintPtrT> tmp235;
    TNode<UintPtrT> tmp236;
    TNode<UintPtrT> tmp237;
    TNode<UintPtrT> tmp238;
    ca_.Bind(&block28, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238);
    TNode<Number> tmp239;
    USE(tmp239);
    tmp239 = LoadDataView32_0(state_, TNode<JSArrayBuffer>{tmp234}, TNode<UintPtrT>{tmp238}, TNode<BoolT>{tmp233}, p_kind);
    ca_.Goto(&block1, tmp227, tmp228, tmp229, tmp230, tmp239);
  }

  if (block29.is_used()) {
    TNode<Context> tmp240;
    TNode<Object> tmp241;
    TNode<Object> tmp242;
    TNode<Object> tmp243;
    TNode<JSDataView> tmp244;
    TNode<UintPtrT> tmp245;
    TNode<BoolT> tmp246;
    TNode<JSArrayBuffer> tmp247;
    TNode<UintPtrT> tmp248;
    TNode<UintPtrT> tmp249;
    TNode<UintPtrT> tmp250;
    TNode<UintPtrT> tmp251;
    ca_.Bind(&block29, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT64_ELEMENTS)))) {
      ca_.Goto(&block31, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251);
    } else {
      ca_.Goto(&block32, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251);
    }
  }

  if (block31.is_used()) {
    TNode<Context> tmp252;
    TNode<Object> tmp253;
    TNode<Object> tmp254;
    TNode<Object> tmp255;
    TNode<JSDataView> tmp256;
    TNode<UintPtrT> tmp257;
    TNode<BoolT> tmp258;
    TNode<JSArrayBuffer> tmp259;
    TNode<UintPtrT> tmp260;
    TNode<UintPtrT> tmp261;
    TNode<UintPtrT> tmp262;
    TNode<UintPtrT> tmp263;
    ca_.Bind(&block31, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263);
    TNode<Number> tmp264;
    USE(tmp264);
    tmp264 = LoadDataViewFloat64_0(state_, TNode<JSArrayBuffer>{tmp259}, TNode<UintPtrT>{tmp263}, TNode<BoolT>{tmp258});
    ca_.Goto(&block1, tmp252, tmp253, tmp254, tmp255, tmp264);
  }

  if (block32.is_used()) {
    TNode<Context> tmp265;
    TNode<Object> tmp266;
    TNode<Object> tmp267;
    TNode<Object> tmp268;
    TNode<JSDataView> tmp269;
    TNode<UintPtrT> tmp270;
    TNode<BoolT> tmp271;
    TNode<JSArrayBuffer> tmp272;
    TNode<UintPtrT> tmp273;
    TNode<UintPtrT> tmp274;
    TNode<UintPtrT> tmp275;
    TNode<UintPtrT> tmp276;
    ca_.Bind(&block32, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGUINT64_ELEMENTS)))) {
      ca_.Goto(&block34, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276);
    } else {
      ca_.Goto(&block35, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276);
    }
  }

  if (block34.is_used()) {
    TNode<Context> tmp277;
    TNode<Object> tmp278;
    TNode<Object> tmp279;
    TNode<Object> tmp280;
    TNode<JSDataView> tmp281;
    TNode<UintPtrT> tmp282;
    TNode<BoolT> tmp283;
    TNode<JSArrayBuffer> tmp284;
    TNode<UintPtrT> tmp285;
    TNode<UintPtrT> tmp286;
    TNode<UintPtrT> tmp287;
    TNode<UintPtrT> tmp288;
    ca_.Bind(&block34, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288);
    TNode<BigInt> tmp289;
    USE(tmp289);
    tmp289 = LoadDataViewBigInt_0(state_, TNode<Context>{tmp277}, TNode<JSArrayBuffer>{tmp284}, TNode<UintPtrT>{tmp288}, TNode<BoolT>{tmp283}, false);
    ca_.Goto(&block1, tmp277, tmp278, tmp279, tmp280, tmp289);
  }

  if (block35.is_used()) {
    TNode<Context> tmp290;
    TNode<Object> tmp291;
    TNode<Object> tmp292;
    TNode<Object> tmp293;
    TNode<JSDataView> tmp294;
    TNode<UintPtrT> tmp295;
    TNode<BoolT> tmp296;
    TNode<JSArrayBuffer> tmp297;
    TNode<UintPtrT> tmp298;
    TNode<UintPtrT> tmp299;
    TNode<UintPtrT> tmp300;
    TNode<UintPtrT> tmp301;
    ca_.Bind(&block35, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGINT64_ELEMENTS)))) {
      ca_.Goto(&block37, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301);
    } else {
      ca_.Goto(&block38, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301);
    }
  }

  if (block37.is_used()) {
    TNode<Context> tmp302;
    TNode<Object> tmp303;
    TNode<Object> tmp304;
    TNode<Object> tmp305;
    TNode<JSDataView> tmp306;
    TNode<UintPtrT> tmp307;
    TNode<BoolT> tmp308;
    TNode<JSArrayBuffer> tmp309;
    TNode<UintPtrT> tmp310;
    TNode<UintPtrT> tmp311;
    TNode<UintPtrT> tmp312;
    TNode<UintPtrT> tmp313;
    ca_.Bind(&block37, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313);
    TNode<BigInt> tmp314;
    USE(tmp314);
    tmp314 = LoadDataViewBigInt_0(state_, TNode<Context>{tmp302}, TNode<JSArrayBuffer>{tmp309}, TNode<UintPtrT>{tmp313}, TNode<BoolT>{tmp308}, true);
    ca_.Goto(&block1, tmp302, tmp303, tmp304, tmp305, tmp314);
  }

  if (block38.is_used()) {
    TNode<Context> tmp315;
    TNode<Object> tmp316;
    TNode<Object> tmp317;
    TNode<Object> tmp318;
    TNode<JSDataView> tmp319;
    TNode<UintPtrT> tmp320;
    TNode<BoolT> tmp321;
    TNode<JSArrayBuffer> tmp322;
    TNode<UintPtrT> tmp323;
    TNode<UintPtrT> tmp324;
    TNode<UintPtrT> tmp325;
    TNode<UintPtrT> tmp326;
    ca_.Bind(&block38, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<Context> tmp327;
    TNode<Object> tmp328;
    TNode<Object> tmp329;
    TNode<Object> tmp330;
    TNode<JSDataView> tmp331;
    ca_.Bind(&block3, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp327}, MessageTemplate::kInvalidDataViewAccessorOffset);
  }

  if (block1.is_used()) {
    TNode<Context> tmp332;
    TNode<Object> tmp333;
    TNode<Object> tmp334;
    TNode<Object> tmp335;
    TNode<Numeric> tmp336;
    ca_.Bind(&block1, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336);
    ca_.Goto(&block40, tmp332, tmp333, tmp334, tmp335, tmp336);
  }

    TNode<Context> tmp337;
    TNode<Object> tmp338;
    TNode<Object> tmp339;
    TNode<Object> tmp340;
    TNode<Numeric> tmp341;
    ca_.Bind(&block40, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341);
  return TNode<Numeric>{tmp341};
}

TF_BUILTIN(DataViewPrototypeGetUint8, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = Undefined_0(state_);
    TNode<Numeric> tmp27;
    USE(tmp27);
    tmp27 = DataViewGet_0(state_, TNode<Context>{tmp23}, TNode<Object>{tmp24}, TNode<Object>{tmp25}, TNode<Object>{tmp26}, UINT8_ELEMENTS);
    arguments.PopAndReturn(tmp27);
  }
}

TF_BUILTIN(DataViewPrototypeGetInt8, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = Undefined_0(state_);
    TNode<Numeric> tmp27;
    USE(tmp27);
    tmp27 = DataViewGet_0(state_, TNode<Context>{tmp23}, TNode<Object>{tmp24}, TNode<Object>{tmp25}, TNode<Object>{tmp26}, INT8_ELEMENTS);
    arguments.PopAndReturn(tmp27);
  }
}

TF_BUILTIN(DataViewPrototypeGetUint16, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, UINT16_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetInt16, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, INT16_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetUint32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, UINT32_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetInt32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, INT32_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetFloat32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, FLOAT32_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetFloat64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, FLOAT64_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetBigUint64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, BIGUINT64_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

TF_BUILTIN(DataViewPrototypeGetBigInt64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Numeric> tmp50;
    USE(tmp50);
    tmp50 = DataViewGet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, BIGINT64_ELEMENTS);
    arguments.PopAndReturn(tmp50);
  }
}

void StoreDataView8_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_value);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<Uint32T> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp3);
    TNode<RawPtrT>tmp4 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp3});
    TNode<Uint32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp5});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp4}, TNode<UintPtrT>{tmp1}, TNode<Uint32T>{tmp6});
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<JSArrayBuffer> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<Uint32T> tmp9;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9);
}

void StoreDataView16_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value, TNode<BoolT> p_requestedLittleEndian) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_value, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp4);
    TNode<RawPtrT>tmp5 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp6});
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp8});
    TNode<Uint32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp9}, TNode<Uint32T>{tmp10});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp7, tmp11);
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp12;
    TNode<UintPtrT> tmp13;
    TNode<Uint32T> tmp14;
    TNode<BoolT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp16}, TNode<UintPtrT>{tmp13}, TNode<Uint32T>{tmp17});
    TNode<UintPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp13}, TNode<UintPtrT>{tmp19});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp16}, TNode<UintPtrT>{tmp20}, TNode<Uint32T>{tmp18});
    ca_.Goto(&block4, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp21;
    TNode<UintPtrT> tmp22;
    TNode<Uint32T> tmp23;
    TNode<BoolT> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<Uint32T> tmp26;
    TNode<Uint32T> tmp27;
    ca_.Bind(&block3, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp25}, TNode<UintPtrT>{tmp22}, TNode<Uint32T>{tmp27});
    TNode<UintPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp28});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp25}, TNode<UintPtrT>{tmp29}, TNode<Uint32T>{tmp26});
    ca_.Goto(&block4, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<Uint32T> tmp32;
    TNode<BoolT> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<Uint32T> tmp35;
    TNode<Uint32T> tmp36;
    ca_.Bind(&block4, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    ca_.Goto(&block5, tmp30, tmp31, tmp32, tmp33);
  }

    TNode<JSArrayBuffer> tmp37;
    TNode<UintPtrT> tmp38;
    TNode<Uint32T> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block5, &tmp37, &tmp38, &tmp39, &tmp40);
}

void StoreDataView32_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value, TNode<BoolT> p_requestedLittleEndian) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_value, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp4);
    TNode<RawPtrT>tmp5 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp4});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp6});
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp8});
    TNode<Uint32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp9}, TNode<Uint32T>{tmp10});
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp12});
    TNode<Uint32T> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp13}, TNode<Uint32T>{tmp14});
    TNode<Uint32T> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp16});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp7, tmp11, tmp15, tmp17);
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Uint32T> tmp20;
    TNode<BoolT> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<Uint32T> tmp23;
    TNode<Uint32T> tmp24;
    TNode<Uint32T> tmp25;
    TNode<Uint32T> tmp26;
    ca_.Bind(&block2, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp22}, TNode<UintPtrT>{tmp19}, TNode<Uint32T>{tmp23});
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp27});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp22}, TNode<UintPtrT>{tmp28}, TNode<Uint32T>{tmp24});
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp29});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp22}, TNode<UintPtrT>{tmp30}, TNode<Uint32T>{tmp25});
    TNode<UintPtrT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp31});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp22}, TNode<UintPtrT>{tmp32}, TNode<Uint32T>{tmp26});
    ca_.Goto(&block4, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<Uint32T> tmp35;
    TNode<BoolT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    ca_.Bind(&block3, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp37}, TNode<UintPtrT>{tmp34}, TNode<Uint32T>{tmp41});
    TNode<UintPtrT> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp42});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp37}, TNode<UintPtrT>{tmp43}, TNode<Uint32T>{tmp40});
    TNode<UintPtrT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp44});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp37}, TNode<UintPtrT>{tmp45}, TNode<Uint32T>{tmp39});
    TNode<UintPtrT> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp46});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp37}, TNode<UintPtrT>{tmp47}, TNode<Uint32T>{tmp38});
    ca_.Goto(&block4, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<Uint32T> tmp50;
    TNode<BoolT> tmp51;
    TNode<RawPtrT> tmp52;
    TNode<Uint32T> tmp53;
    TNode<Uint32T> tmp54;
    TNode<Uint32T> tmp55;
    TNode<Uint32T> tmp56;
    ca_.Bind(&block4, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    ca_.Goto(&block5, tmp48, tmp49, tmp50, tmp51);
  }

    TNode<JSArrayBuffer> tmp57;
    TNode<UintPtrT> tmp58;
    TNode<Uint32T> tmp59;
    TNode<BoolT> tmp60;
    ca_.Bind(&block5, &tmp57, &tmp58, &tmp59, &tmp60);
}

void StoreDataView64_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, TNode<BoolT> p_requestedLittleEndian) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, Uint32T, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, Uint32T, BoolT, RawPtrT, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, Uint32T, Uint32T, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_lowWord, p_highWord, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp5);
    TNode<RawPtrT>tmp6 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp0, tmp5});
    TNode<Uint32T> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp7});
    TNode<Uint32T> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp9});
    TNode<Uint32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp10}, TNode<Uint32T>{tmp11});
    TNode<Uint32T> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp13});
    TNode<Uint32T> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp14}, TNode<Uint32T>{tmp15});
    TNode<Uint32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp2}, TNode<Uint32T>{tmp17});
    TNode<Uint32T> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp19});
    TNode<Uint32T> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_uint32_constexpr_int31_0(state_, 8);
    TNode<Uint32T> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp21});
    TNode<Uint32T> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp22}, TNode<Uint32T>{tmp23});
    TNode<Uint32T> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_uint32_constexpr_int31_0(state_, 16);
    TNode<Uint32T> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp25});
    TNode<Uint32T> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_uint32_constexpr_int31_0(state_, 0xFF);
    TNode<Uint32T> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).Word32And(TNode<Uint32T>{tmp26}, TNode<Uint32T>{tmp27});
    TNode<Uint32T> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uint32_constexpr_int31_0(state_, 24);
    TNode<Uint32T> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).Word32Shr(TNode<Uint32T>{tmp3}, TNode<Uint32T>{tmp29});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp8, tmp12, tmp16, tmp18, tmp20, tmp24, tmp28, tmp30);
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<Uint32T> tmp33;
    TNode<Uint32T> tmp34;
    TNode<BoolT> tmp35;
    TNode<RawPtrT> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    TNode<Uint32T> tmp42;
    TNode<Uint32T> tmp43;
    TNode<Uint32T> tmp44;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp32}, TNode<Uint32T>{tmp37});
    TNode<UintPtrT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp45});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp46}, TNode<Uint32T>{tmp38});
    TNode<UintPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp47});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp48}, TNode<Uint32T>{tmp39});
    TNode<UintPtrT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp49});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp50}, TNode<Uint32T>{tmp40});
    TNode<UintPtrT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_uintptr_constexpr_int31_0(state_, 4);
    TNode<UintPtrT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp51});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp52}, TNode<Uint32T>{tmp41});
    TNode<UintPtrT> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_uintptr_constexpr_int31_0(state_, 5);
    TNode<UintPtrT> tmp54;
    USE(tmp54);
    tmp54 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp53});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp54}, TNode<Uint32T>{tmp42});
    TNode<UintPtrT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_uintptr_constexpr_int31_0(state_, 6);
    TNode<UintPtrT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp55});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp56}, TNode<Uint32T>{tmp43});
    TNode<UintPtrT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_uintptr_constexpr_int31_0(state_, 7);
    TNode<UintPtrT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp57});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp36}, TNode<UintPtrT>{tmp58}, TNode<Uint32T>{tmp44});
    ca_.Goto(&block4, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<Uint32T> tmp61;
    TNode<Uint32T> tmp62;
    TNode<BoolT> tmp63;
    TNode<RawPtrT> tmp64;
    TNode<Uint32T> tmp65;
    TNode<Uint32T> tmp66;
    TNode<Uint32T> tmp67;
    TNode<Uint32T> tmp68;
    TNode<Uint32T> tmp69;
    TNode<Uint32T> tmp70;
    TNode<Uint32T> tmp71;
    TNode<Uint32T> tmp72;
    ca_.Bind(&block3, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp60}, TNode<Uint32T>{tmp72});
    TNode<UintPtrT> tmp73;
    USE(tmp73);
    tmp73 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp74;
    USE(tmp74);
    tmp74 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp73});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp74}, TNode<Uint32T>{tmp71});
    TNode<UintPtrT> tmp75;
    USE(tmp75);
    tmp75 = FromConstexpr_uintptr_constexpr_int31_0(state_, 2);
    TNode<UintPtrT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp75});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp76}, TNode<Uint32T>{tmp70});
    TNode<UintPtrT> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    TNode<UintPtrT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp77});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp78}, TNode<Uint32T>{tmp69});
    TNode<UintPtrT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_uintptr_constexpr_int31_0(state_, 4);
    TNode<UintPtrT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp79});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp80}, TNode<Uint32T>{tmp68});
    TNode<UintPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_uintptr_constexpr_int31_0(state_, 5);
    TNode<UintPtrT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp81});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp82}, TNode<Uint32T>{tmp67});
    TNode<UintPtrT> tmp83;
    USE(tmp83);
    tmp83 = FromConstexpr_uintptr_constexpr_int31_0(state_, 6);
    TNode<UintPtrT> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp83});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp84}, TNode<Uint32T>{tmp66});
    TNode<UintPtrT> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_uintptr_constexpr_int31_0(state_, 7);
    TNode<UintPtrT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp60}, TNode<UintPtrT>{tmp85});
    DataViewBuiltinsAssembler(state_).StoreWord8(TNode<RawPtrT>{tmp64}, TNode<UintPtrT>{tmp86}, TNode<Uint32T>{tmp65});
    ca_.Goto(&block4, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72);
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp87;
    TNode<UintPtrT> tmp88;
    TNode<Uint32T> tmp89;
    TNode<Uint32T> tmp90;
    TNode<BoolT> tmp91;
    TNode<RawPtrT> tmp92;
    TNode<Uint32T> tmp93;
    TNode<Uint32T> tmp94;
    TNode<Uint32T> tmp95;
    TNode<Uint32T> tmp96;
    TNode<Uint32T> tmp97;
    TNode<Uint32T> tmp98;
    TNode<Uint32T> tmp99;
    TNode<Uint32T> tmp100;
    ca_.Bind(&block4, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    ca_.Goto(&block5, tmp87, tmp88, tmp89, tmp90, tmp91);
  }

    TNode<JSArrayBuffer> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<Uint32T> tmp103;
    TNode<Uint32T> tmp104;
    TNode<BoolT> tmp105;
    ca_.Bind(&block5, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
}

void StoreDataViewBigInt_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BigInt> p_bigIntValue, TNode<BoolT> p_requestedLittleEndian) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT, Uint32T, Uint32T, Uint32T, Uint32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArrayBuffer, UintPtrT, BigInt, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_buffer, p_offset, p_bigIntValue, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<JSArrayBuffer> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BigInt> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Uint32T> tmp4;
    USE(tmp4);
    tmp4 = DataViewBuiltinsAssembler(state_).DataViewDecodeBigIntLength(TNode<BigInt>{tmp2});
    TNode<Uint32T> tmp5;
    USE(tmp5);
    tmp5 = DataViewBuiltinsAssembler(state_).DataViewDecodeBigIntSign(TNode<BigInt>{tmp2});
    TNode<Uint32T> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<Uint32T> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<Uint32T> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp4}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block2.is_used()) {
    TNode<JSArrayBuffer> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<BigInt> tmp12;
    TNode<BoolT> tmp13;
    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<Uint32T> tmp16;
    TNode<Uint32T> tmp17;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block4, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
    } else {
      ca_.Goto(&block5, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
    }
  }

  if (block4.is_used()) {
    TNode<JSArrayBuffer> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<BigInt> tmp20;
    TNode<BoolT> tmp21;
    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    TNode<Uint32T> tmp24;
    TNode<Uint32T> tmp25;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp20}, TNode<IntPtrT>{tmp26});
    TNode<Uint32T> tmp28;
    USE(tmp28);
    tmp28 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT>{tmp27});
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uintptr_constexpr_int31_0(state_, 32);
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp27}, TNode<UintPtrT>{tmp29});
    TNode<Uint32T> tmp31;
    USE(tmp31);
    tmp31 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT>{tmp30});
    ca_.Goto(&block6, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp28, tmp31);
  }

  if (block5.is_used()) {
    TNode<JSArrayBuffer> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<BigInt> tmp34;
    TNode<BoolT> tmp35;
    TNode<Uint32T> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    ca_.Bind(&block5, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp34}, TNode<IntPtrT>{tmp40});
    TNode<Uint32T> tmp42;
    USE(tmp42);
    tmp42 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT>{tmp41});
    TNode<Uint32T> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_uint32_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T>{tmp36}, TNode<Uint32T>{tmp43});
    ca_.Branch(tmp44, &block7, &block8, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp42, tmp39);
  }

  if (block7.is_used()) {
    TNode<JSArrayBuffer> tmp45;
    TNode<UintPtrT> tmp46;
    TNode<BigInt> tmp47;
    TNode<BoolT> tmp48;
    TNode<Uint32T> tmp49;
    TNode<Uint32T> tmp50;
    TNode<Uint32T> tmp51;
    TNode<Uint32T> tmp52;
    ca_.Bind(&block7, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<IntPtrT> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp54;
    USE(tmp54);
    tmp54 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp47}, TNode<IntPtrT>{tmp53});
    TNode<Uint32T> tmp55;
    USE(tmp55);
    tmp55 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT>{tmp54});
    ca_.Goto(&block8, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp55);
  }

  if (block8.is_used()) {
    TNode<JSArrayBuffer> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<BigInt> tmp58;
    TNode<BoolT> tmp59;
    TNode<Uint32T> tmp60;
    TNode<Uint32T> tmp61;
    TNode<Uint32T> tmp62;
    TNode<Uint32T> tmp63;
    ca_.Bind(&block8, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block6, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block6.is_used()) {
    TNode<JSArrayBuffer> tmp64;
    TNode<UintPtrT> tmp65;
    TNode<BigInt> tmp66;
    TNode<BoolT> tmp67;
    TNode<Uint32T> tmp68;
    TNode<Uint32T> tmp69;
    TNode<Uint32T> tmp70;
    TNode<Uint32T> tmp71;
    ca_.Bind(&block6, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    ca_.Goto(&block3, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71);
  }

  if (block3.is_used()) {
    TNode<JSArrayBuffer> tmp72;
    TNode<UintPtrT> tmp73;
    TNode<BigInt> tmp74;
    TNode<BoolT> tmp75;
    TNode<Uint32T> tmp76;
    TNode<Uint32T> tmp77;
    TNode<Uint32T> tmp78;
    TNode<Uint32T> tmp79;
    ca_.Bind(&block3, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    TNode<Uint32T> tmp80;
    USE(tmp80);
    tmp80 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp77}, TNode<Uint32T>{tmp80});
    ca_.Branch(tmp81, &block9, &block10, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
  }

  if (block9.is_used()) {
    TNode<JSArrayBuffer> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<BigInt> tmp84;
    TNode<BoolT> tmp85;
    TNode<Uint32T> tmp86;
    TNode<Uint32T> tmp87;
    TNode<Uint32T> tmp88;
    TNode<Uint32T> tmp89;
    ca_.Bind(&block9, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<Int32T> tmp90;
    USE(tmp90);
    tmp90 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp89});
    TNode<Int32T> tmp91;
    USE(tmp91);
    tmp91 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Int32T> tmp92;
    USE(tmp92);
    tmp92 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp91}, TNode<Int32T>{tmp90});
    TNode<Uint32T> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp92});
    TNode<Uint32T> tmp94;
    USE(tmp94);
    tmp94 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp95;
    USE(tmp95);
    tmp95 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp88}, TNode<Uint32T>{tmp94});
    ca_.Branch(tmp95, &block11, &block12, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp93);
  }

  if (block11.is_used()) {
    TNode<JSArrayBuffer> tmp96;
    TNode<UintPtrT> tmp97;
    TNode<BigInt> tmp98;
    TNode<BoolT> tmp99;
    TNode<Uint32T> tmp100;
    TNode<Uint32T> tmp101;
    TNode<Uint32T> tmp102;
    TNode<Uint32T> tmp103;
    ca_.Bind(&block11, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
    TNode<Int32T> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp103});
    TNode<Int32T> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp104}, TNode<Int32T>{tmp105});
    TNode<Uint32T> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp106});
    ca_.Goto(&block12, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp107);
  }

  if (block12.is_used()) {
    TNode<JSArrayBuffer> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<BigInt> tmp110;
    TNode<BoolT> tmp111;
    TNode<Uint32T> tmp112;
    TNode<Uint32T> tmp113;
    TNode<Uint32T> tmp114;
    TNode<Uint32T> tmp115;
    ca_.Bind(&block12, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115);
    TNode<Int32T> tmp116;
    USE(tmp116);
    tmp116 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp114});
    TNode<Int32T> tmp117;
    USE(tmp117);
    tmp117 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Int32T> tmp118;
    USE(tmp118);
    tmp118 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp117}, TNode<Int32T>{tmp116});
    TNode<Uint32T> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp118});
    ca_.Goto(&block10, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp119, tmp115);
  }

  if (block10.is_used()) {
    TNode<JSArrayBuffer> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<BigInt> tmp122;
    TNode<BoolT> tmp123;
    TNode<Uint32T> tmp124;
    TNode<Uint32T> tmp125;
    TNode<Uint32T> tmp126;
    TNode<Uint32T> tmp127;
    ca_.Bind(&block10, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    StoreDataView64_0(state_, TNode<JSArrayBuffer>{tmp120}, TNode<UintPtrT>{tmp121}, TNode<Uint32T>{tmp126}, TNode<Uint32T>{tmp127}, TNode<BoolT>{tmp123});
    ca_.Goto(&block13, tmp120, tmp121, tmp122, tmp123);
  }

    TNode<JSArrayBuffer> tmp128;
    TNode<UintPtrT> tmp129;
    TNode<BigInt> tmp130;
    TNode<BoolT> tmp131;
    ca_.Bind(&block13, &tmp128, &tmp129, &tmp130, &tmp131);
}

TNode<Object> DataViewSet_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_requestIndex, TNode<Object> p_value, TNode<Object> p_requestedLittleEndian, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, Object, Context, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Number, Float64T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView, UintPtrT, BoolT, JSArrayBuffer, Numeric, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, JSDataView> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_requestIndex, p_value, p_requestedLittleEndian);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = MakeDataViewSetterNameString_0(state_, p_kind);
    TNode<JSDataView> tmp6;
    USE(tmp6);
    tmp6 = ValidateDataView_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp5});
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = ToIndex_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp2, tmp0, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<JSDataView> tmp13;
    TNode<Object> tmp14;
    TNode<Context> tmp15;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    ca_.Goto(&block3, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<JSDataView> tmp21;
    TNode<Object> tmp22;
    TNode<Context> tmp23;
    TNode<UintPtrT> tmp24;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = ToBoolean_0(state_, TNode<Object>{tmp20});
    TNode<IntPtrT> tmp26 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp26);
    TNode<JSArrayBuffer>tmp27 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp21, tmp26});
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGUINT64_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGINT64_ELEMENTS))))) {
      ca_.Goto(&block6, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp24, tmp25, tmp27, ca_.Uninitialized<Numeric>());
    } else {
      ca_.Goto(&block7, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp24, tmp25, tmp27, ca_.Uninitialized<Numeric>());
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<JSDataView> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<BoolT> tmp35;
    TNode<JSArrayBuffer> tmp36;
    TNode<Numeric> tmp37;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<BigInt> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{tmp28}, TNode<Object>{tmp31});
    ca_.Goto(&block8, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp38);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<JSDataView> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<BoolT> tmp46;
    TNode<JSArrayBuffer> tmp47;
    TNode<Numeric> tmp48;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<Number> tmp49;
    USE(tmp49);
    tmp49 = CodeStubAssembler(state_).ToNumber(TNode<Context>{tmp39}, TNode<Object>{tmp42});
    ca_.Goto(&block8, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp49);
  }

  if (block8.is_used()) {
    TNode<Context> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<JSDataView> tmp55;
    TNode<UintPtrT> tmp56;
    TNode<BoolT> tmp57;
    TNode<JSArrayBuffer> tmp58;
    TNode<Numeric> tmp59;
    ca_.Bind(&block8, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp58});
    ca_.Branch(tmp60, &block9, &block10, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59);
  }

  if (block9.is_used()) {
    TNode<Context> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    TNode<JSDataView> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<BoolT> tmp68;
    TNode<JSArrayBuffer> tmp69;
    TNode<Numeric> tmp70;
    ca_.Bind(&block9, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<String> tmp71;
    USE(tmp71);
    tmp71 = MakeDataViewSetterNameString_0(state_, p_kind);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp61}, MessageTemplate::kDetachedOperation, TNode<Object>{tmp71});
  }

  if (block10.is_used()) {
    TNode<Context> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<JSDataView> tmp77;
    TNode<UintPtrT> tmp78;
    TNode<BoolT> tmp79;
    TNode<JSArrayBuffer> tmp80;
    TNode<Numeric> tmp81;
    ca_.Bind(&block10, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<IntPtrT> tmp82 = ca_.IntPtrConstant(JSArrayBufferView::kByteOffsetOffset);
    USE(tmp82);
    TNode<UintPtrT>tmp83 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp77, tmp82});
    TNode<IntPtrT> tmp84 = ca_.IntPtrConstant(JSArrayBufferView::kByteLengthOffset);
    USE(tmp84);
    TNode<UintPtrT>tmp85 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp77, tmp84});
    TNode<UintPtrT> tmp86;
    USE(tmp86);
    tmp86 = FromConstexpr_uintptr_constexpr_int31_0(state_, (DataViewBuiltinsAssembler(state_).DataViewElementSize(p_kind)));
    compiler::CodeAssemblerLabel label0(&ca_);
    CheckIntegerIndexAdditionOverflow_0(state_, TNode<UintPtrT>{tmp78}, TNode<UintPtrT>{tmp86}, TNode<UintPtrT>{tmp85}, &label0);
    ca_.Goto(&block11, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp83, tmp85, tmp86, tmp78, tmp86, tmp85);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp83, tmp85, tmp86, tmp78, tmp86, tmp85);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp87;
    TNode<Object> tmp88;
    TNode<Object> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<JSDataView> tmp92;
    TNode<UintPtrT> tmp93;
    TNode<BoolT> tmp94;
    TNode<JSArrayBuffer> tmp95;
    TNode<Numeric> tmp96;
    TNode<UintPtrT> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    TNode<UintPtrT> tmp101;
    TNode<UintPtrT> tmp102;
    ca_.Bind(&block12, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    ca_.Goto(&block3, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92);
  }

  if (block11.is_used()) {
    TNode<Context> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<Object> tmp107;
    TNode<JSDataView> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<BoolT> tmp110;
    TNode<JSArrayBuffer> tmp111;
    TNode<Numeric> tmp112;
    TNode<UintPtrT> tmp113;
    TNode<UintPtrT> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<UintPtrT> tmp116;
    TNode<UintPtrT> tmp117;
    TNode<UintPtrT> tmp118;
    ca_.Bind(&block11, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    TNode<UintPtrT> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp109}, TNode<UintPtrT>{tmp113});
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGUINT64_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, BIGINT64_ELEMENTS))))) {
      ca_.Goto(&block13, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp119);
    } else {
      ca_.Goto(&block14, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp119);
    }
  }

  if (block13.is_used()) {
    TNode<Context> tmp120;
    TNode<Object> tmp121;
    TNode<Object> tmp122;
    TNode<Object> tmp123;
    TNode<Object> tmp124;
    TNode<JSDataView> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<BoolT> tmp127;
    TNode<JSArrayBuffer> tmp128;
    TNode<Numeric> tmp129;
    TNode<UintPtrT> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<UintPtrT> tmp133;
    ca_.Bind(&block13, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<BigInt> tmp134;
    USE(tmp134);
    tmp134 = TORQUE_CAST(TNode<Numeric>{tmp129});
    StoreDataViewBigInt_0(state_, TNode<JSArrayBuffer>{tmp128}, TNode<UintPtrT>{tmp133}, TNode<BigInt>{tmp134}, TNode<BoolT>{tmp127});
    ca_.Goto(&block15, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133);
  }

  if (block14.is_used()) {
    TNode<Context> tmp135;
    TNode<Object> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    TNode<Object> tmp139;
    TNode<JSDataView> tmp140;
    TNode<UintPtrT> tmp141;
    TNode<BoolT> tmp142;
    TNode<JSArrayBuffer> tmp143;
    TNode<Numeric> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<UintPtrT> tmp146;
    TNode<UintPtrT> tmp147;
    TNode<UintPtrT> tmp148;
    ca_.Bind(&block14, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    TNode<Number> tmp149;
    USE(tmp149);
    tmp149 = TORQUE_CAST(TNode<Numeric>{tmp144});
    TNode<Float64T> tmp150;
    USE(tmp150);
    tmp150 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number>{tmp149});
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT8_ELEMENTS))))) {
      ca_.Goto(&block16, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150);
    } else {
      ca_.Goto(&block17, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp151;
    TNode<Object> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<JSDataView> tmp156;
    TNode<UintPtrT> tmp157;
    TNode<BoolT> tmp158;
    TNode<JSArrayBuffer> tmp159;
    TNode<Numeric> tmp160;
    TNode<UintPtrT> tmp161;
    TNode<UintPtrT> tmp162;
    TNode<UintPtrT> tmp163;
    TNode<UintPtrT> tmp164;
    TNode<Number> tmp165;
    TNode<Float64T> tmp166;
    ca_.Bind(&block16, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166);
    TNode<Uint32T> tmp167;
    USE(tmp167);
    tmp167 = CodeStubAssembler(state_).TruncateFloat64ToWord32(TNode<Float64T>{tmp166});
    StoreDataView8_0(state_, TNode<JSArrayBuffer>{tmp159}, TNode<UintPtrT>{tmp164}, TNode<Uint32T>{tmp167});
    ca_.Goto(&block18, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166);
  }

  if (block17.is_used()) {
    TNode<Context> tmp168;
    TNode<Object> tmp169;
    TNode<Object> tmp170;
    TNode<Object> tmp171;
    TNode<Object> tmp172;
    TNode<JSDataView> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<BoolT> tmp175;
    TNode<JSArrayBuffer> tmp176;
    TNode<Numeric> tmp177;
    TNode<UintPtrT> tmp178;
    TNode<UintPtrT> tmp179;
    TNode<UintPtrT> tmp180;
    TNode<UintPtrT> tmp181;
    TNode<Number> tmp182;
    TNode<Float64T> tmp183;
    ca_.Bind(&block17, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183);
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT16_ELEMENTS))))) {
      ca_.Goto(&block19, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183);
    } else {
      ca_.Goto(&block20, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183);
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp186;
    TNode<Object> tmp187;
    TNode<Object> tmp188;
    TNode<JSDataView> tmp189;
    TNode<UintPtrT> tmp190;
    TNode<BoolT> tmp191;
    TNode<JSArrayBuffer> tmp192;
    TNode<Numeric> tmp193;
    TNode<UintPtrT> tmp194;
    TNode<UintPtrT> tmp195;
    TNode<UintPtrT> tmp196;
    TNode<UintPtrT> tmp197;
    TNode<Number> tmp198;
    TNode<Float64T> tmp199;
    ca_.Bind(&block19, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199);
    TNode<Uint32T> tmp200;
    USE(tmp200);
    tmp200 = CodeStubAssembler(state_).TruncateFloat64ToWord32(TNode<Float64T>{tmp199});
    StoreDataView16_0(state_, TNode<JSArrayBuffer>{tmp192}, TNode<UintPtrT>{tmp197}, TNode<Uint32T>{tmp200}, TNode<BoolT>{tmp191});
    ca_.Goto(&block21, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199);
  }

  if (block20.is_used()) {
    TNode<Context> tmp201;
    TNode<Object> tmp202;
    TNode<Object> tmp203;
    TNode<Object> tmp204;
    TNode<Object> tmp205;
    TNode<JSDataView> tmp206;
    TNode<UintPtrT> tmp207;
    TNode<BoolT> tmp208;
    TNode<JSArrayBuffer> tmp209;
    TNode<Numeric> tmp210;
    TNode<UintPtrT> tmp211;
    TNode<UintPtrT> tmp212;
    TNode<UintPtrT> tmp213;
    TNode<UintPtrT> tmp214;
    TNode<Number> tmp215;
    TNode<Float64T> tmp216;
    ca_.Bind(&block20, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT32_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, INT32_ELEMENTS))))) {
      ca_.Goto(&block22, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216);
    } else {
      ca_.Goto(&block23, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216);
    }
  }

  if (block22.is_used()) {
    TNode<Context> tmp217;
    TNode<Object> tmp218;
    TNode<Object> tmp219;
    TNode<Object> tmp220;
    TNode<Object> tmp221;
    TNode<JSDataView> tmp222;
    TNode<UintPtrT> tmp223;
    TNode<BoolT> tmp224;
    TNode<JSArrayBuffer> tmp225;
    TNode<Numeric> tmp226;
    TNode<UintPtrT> tmp227;
    TNode<UintPtrT> tmp228;
    TNode<UintPtrT> tmp229;
    TNode<UintPtrT> tmp230;
    TNode<Number> tmp231;
    TNode<Float64T> tmp232;
    ca_.Bind(&block22, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232);
    TNode<Uint32T> tmp233;
    USE(tmp233);
    tmp233 = CodeStubAssembler(state_).TruncateFloat64ToWord32(TNode<Float64T>{tmp232});
    StoreDataView32_0(state_, TNode<JSArrayBuffer>{tmp225}, TNode<UintPtrT>{tmp230}, TNode<Uint32T>{tmp233}, TNode<BoolT>{tmp224});
    ca_.Goto(&block24, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232);
  }

  if (block23.is_used()) {
    TNode<Context> tmp234;
    TNode<Object> tmp235;
    TNode<Object> tmp236;
    TNode<Object> tmp237;
    TNode<Object> tmp238;
    TNode<JSDataView> tmp239;
    TNode<UintPtrT> tmp240;
    TNode<BoolT> tmp241;
    TNode<JSArrayBuffer> tmp242;
    TNode<Numeric> tmp243;
    TNode<UintPtrT> tmp244;
    TNode<UintPtrT> tmp245;
    TNode<UintPtrT> tmp246;
    TNode<UintPtrT> tmp247;
    TNode<Number> tmp248;
    TNode<Float64T> tmp249;
    ca_.Bind(&block23, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT32_ELEMENTS)))) {
      ca_.Goto(&block25, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249);
    } else {
      ca_.Goto(&block26, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249);
    }
  }

  if (block25.is_used()) {
    TNode<Context> tmp250;
    TNode<Object> tmp251;
    TNode<Object> tmp252;
    TNode<Object> tmp253;
    TNode<Object> tmp254;
    TNode<JSDataView> tmp255;
    TNode<UintPtrT> tmp256;
    TNode<BoolT> tmp257;
    TNode<JSArrayBuffer> tmp258;
    TNode<Numeric> tmp259;
    TNode<UintPtrT> tmp260;
    TNode<UintPtrT> tmp261;
    TNode<UintPtrT> tmp262;
    TNode<UintPtrT> tmp263;
    TNode<Number> tmp264;
    TNode<Float64T> tmp265;
    ca_.Bind(&block25, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265);
    TNode<Float32T> tmp266;
    USE(tmp266);
    tmp266 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp265});
    TNode<Uint32T> tmp267;
    USE(tmp267);
    tmp267 = CodeStubAssembler(state_).BitcastFloat32ToInt32(TNode<Float32T>{tmp266});
    StoreDataView32_0(state_, TNode<JSArrayBuffer>{tmp258}, TNode<UintPtrT>{tmp263}, TNode<Uint32T>{tmp267}, TNode<BoolT>{tmp257});
    ca_.Goto(&block27, tmp250, tmp251, tmp252, tmp253, tmp254, tmp255, tmp256, tmp257, tmp258, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265);
  }

  if (block26.is_used()) {
    TNode<Context> tmp268;
    TNode<Object> tmp269;
    TNode<Object> tmp270;
    TNode<Object> tmp271;
    TNode<Object> tmp272;
    TNode<JSDataView> tmp273;
    TNode<UintPtrT> tmp274;
    TNode<BoolT> tmp275;
    TNode<JSArrayBuffer> tmp276;
    TNode<Numeric> tmp277;
    TNode<UintPtrT> tmp278;
    TNode<UintPtrT> tmp279;
    TNode<UintPtrT> tmp280;
    TNode<UintPtrT> tmp281;
    TNode<Number> tmp282;
    TNode<Float64T> tmp283;
    ca_.Bind(&block26, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283);
    if (((CodeStubAssembler(state_).ElementsKindEqual(p_kind, FLOAT64_ELEMENTS)))) {
      ca_.Goto(&block28, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276, tmp277, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283);
    } else {
      ca_.Goto(&block29, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276, tmp277, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283);
    }
  }

  if (block28.is_used()) {
    TNode<Context> tmp284;
    TNode<Object> tmp285;
    TNode<Object> tmp286;
    TNode<Object> tmp287;
    TNode<Object> tmp288;
    TNode<JSDataView> tmp289;
    TNode<UintPtrT> tmp290;
    TNode<BoolT> tmp291;
    TNode<JSArrayBuffer> tmp292;
    TNode<Numeric> tmp293;
    TNode<UintPtrT> tmp294;
    TNode<UintPtrT> tmp295;
    TNode<UintPtrT> tmp296;
    TNode<UintPtrT> tmp297;
    TNode<Number> tmp298;
    TNode<Float64T> tmp299;
    ca_.Bind(&block28, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299);
    TNode<Uint32T> tmp300;
    USE(tmp300);
    tmp300 = CodeStubAssembler(state_).Float64ExtractLowWord32(TNode<Float64T>{tmp299});
    TNode<Uint32T> tmp301;
    USE(tmp301);
    tmp301 = CodeStubAssembler(state_).Float64ExtractHighWord32(TNode<Float64T>{tmp299});
    StoreDataView64_0(state_, TNode<JSArrayBuffer>{tmp292}, TNode<UintPtrT>{tmp297}, TNode<Uint32T>{tmp300}, TNode<Uint32T>{tmp301}, TNode<BoolT>{tmp291});
    ca_.Goto(&block30, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299);
  }

  if (block29.is_used()) {
    TNode<Context> tmp302;
    TNode<Object> tmp303;
    TNode<Object> tmp304;
    TNode<Object> tmp305;
    TNode<Object> tmp306;
    TNode<JSDataView> tmp307;
    TNode<UintPtrT> tmp308;
    TNode<BoolT> tmp309;
    TNode<JSArrayBuffer> tmp310;
    TNode<Numeric> tmp311;
    TNode<UintPtrT> tmp312;
    TNode<UintPtrT> tmp313;
    TNode<UintPtrT> tmp314;
    TNode<UintPtrT> tmp315;
    TNode<Number> tmp316;
    TNode<Float64T> tmp317;
    ca_.Bind(&block29, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317);
    ca_.Goto(&block30, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317);
  }

  if (block30.is_used()) {
    TNode<Context> tmp318;
    TNode<Object> tmp319;
    TNode<Object> tmp320;
    TNode<Object> tmp321;
    TNode<Object> tmp322;
    TNode<JSDataView> tmp323;
    TNode<UintPtrT> tmp324;
    TNode<BoolT> tmp325;
    TNode<JSArrayBuffer> tmp326;
    TNode<Numeric> tmp327;
    TNode<UintPtrT> tmp328;
    TNode<UintPtrT> tmp329;
    TNode<UintPtrT> tmp330;
    TNode<UintPtrT> tmp331;
    TNode<Number> tmp332;
    TNode<Float64T> tmp333;
    ca_.Bind(&block30, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333);
    ca_.Goto(&block27, tmp318, tmp319, tmp320, tmp321, tmp322, tmp323, tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333);
  }

  if (block27.is_used()) {
    TNode<Context> tmp334;
    TNode<Object> tmp335;
    TNode<Object> tmp336;
    TNode<Object> tmp337;
    TNode<Object> tmp338;
    TNode<JSDataView> tmp339;
    TNode<UintPtrT> tmp340;
    TNode<BoolT> tmp341;
    TNode<JSArrayBuffer> tmp342;
    TNode<Numeric> tmp343;
    TNode<UintPtrT> tmp344;
    TNode<UintPtrT> tmp345;
    TNode<UintPtrT> tmp346;
    TNode<UintPtrT> tmp347;
    TNode<Number> tmp348;
    TNode<Float64T> tmp349;
    ca_.Bind(&block27, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349);
    ca_.Goto(&block24, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp348, tmp349);
  }

  if (block24.is_used()) {
    TNode<Context> tmp350;
    TNode<Object> tmp351;
    TNode<Object> tmp352;
    TNode<Object> tmp353;
    TNode<Object> tmp354;
    TNode<JSDataView> tmp355;
    TNode<UintPtrT> tmp356;
    TNode<BoolT> tmp357;
    TNode<JSArrayBuffer> tmp358;
    TNode<Numeric> tmp359;
    TNode<UintPtrT> tmp360;
    TNode<UintPtrT> tmp361;
    TNode<UintPtrT> tmp362;
    TNode<UintPtrT> tmp363;
    TNode<Number> tmp364;
    TNode<Float64T> tmp365;
    ca_.Bind(&block24, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365);
    ca_.Goto(&block21, tmp350, tmp351, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362, tmp363, tmp364, tmp365);
  }

  if (block21.is_used()) {
    TNode<Context> tmp366;
    TNode<Object> tmp367;
    TNode<Object> tmp368;
    TNode<Object> tmp369;
    TNode<Object> tmp370;
    TNode<JSDataView> tmp371;
    TNode<UintPtrT> tmp372;
    TNode<BoolT> tmp373;
    TNode<JSArrayBuffer> tmp374;
    TNode<Numeric> tmp375;
    TNode<UintPtrT> tmp376;
    TNode<UintPtrT> tmp377;
    TNode<UintPtrT> tmp378;
    TNode<UintPtrT> tmp379;
    TNode<Number> tmp380;
    TNode<Float64T> tmp381;
    ca_.Bind(&block21, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381);
    ca_.Goto(&block18, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp377, tmp378, tmp379, tmp380, tmp381);
  }

  if (block18.is_used()) {
    TNode<Context> tmp382;
    TNode<Object> tmp383;
    TNode<Object> tmp384;
    TNode<Object> tmp385;
    TNode<Object> tmp386;
    TNode<JSDataView> tmp387;
    TNode<UintPtrT> tmp388;
    TNode<BoolT> tmp389;
    TNode<JSArrayBuffer> tmp390;
    TNode<Numeric> tmp391;
    TNode<UintPtrT> tmp392;
    TNode<UintPtrT> tmp393;
    TNode<UintPtrT> tmp394;
    TNode<UintPtrT> tmp395;
    TNode<Number> tmp396;
    TNode<Float64T> tmp397;
    ca_.Bind(&block18, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397);
    ca_.Goto(&block15, tmp382, tmp383, tmp384, tmp385, tmp386, tmp387, tmp388, tmp389, tmp390, tmp391, tmp392, tmp393, tmp394, tmp395);
  }

  if (block15.is_used()) {
    TNode<Context> tmp398;
    TNode<Object> tmp399;
    TNode<Object> tmp400;
    TNode<Object> tmp401;
    TNode<Object> tmp402;
    TNode<JSDataView> tmp403;
    TNode<UintPtrT> tmp404;
    TNode<BoolT> tmp405;
    TNode<JSArrayBuffer> tmp406;
    TNode<Numeric> tmp407;
    TNode<UintPtrT> tmp408;
    TNode<UintPtrT> tmp409;
    TNode<UintPtrT> tmp410;
    TNode<UintPtrT> tmp411;
    ca_.Bind(&block15, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404, &tmp405, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411);
    TNode<Oddball> tmp412;
    USE(tmp412);
    tmp412 = Undefined_0(state_);
    ca_.Goto(&block31, tmp398, tmp399, tmp400, tmp401, tmp402, tmp412);
  }

  if (block3.is_used()) {
    TNode<Context> tmp413;
    TNode<Object> tmp414;
    TNode<Object> tmp415;
    TNode<Object> tmp416;
    TNode<Object> tmp417;
    TNode<JSDataView> tmp418;
    ca_.Bind(&block3, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp413}, MessageTemplate::kInvalidDataViewAccessorOffset);
  }

    TNode<Context> tmp419;
    TNode<Object> tmp420;
    TNode<Object> tmp421;
    TNode<Object> tmp422;
    TNode<Object> tmp423;
    TNode<Object> tmp424;
    ca_.Bind(&block31, &tmp419, &tmp420, &tmp421, &tmp422, &tmp423, &tmp424);
  return TNode<Object>{tmp424};
}

TF_BUILTIN(DataViewPrototypeSetUint8, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Oddball> tmp50;
    USE(tmp50);
    tmp50 = Undefined_0(state_);
    TNode<Object> tmp51;
    USE(tmp51);
    tmp51 = DataViewSet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, TNode<Object>{tmp50}, UINT8_ELEMENTS);
    arguments.PopAndReturn(tmp51);
  }
}

TF_BUILTIN(DataViewPrototypeSetInt8, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Oddball> tmp50;
    USE(tmp50);
    tmp50 = Undefined_0(state_);
    TNode<Object> tmp51;
    USE(tmp51);
    tmp51 = DataViewSet_0(state_, TNode<Context>{tmp46}, TNode<Object>{tmp47}, TNode<Object>{tmp48}, TNode<Object>{tmp49}, TNode<Object>{tmp50}, INT8_ELEMENTS);
    arguments.PopAndReturn(tmp51);
  }
}

TF_BUILTIN(DataViewPrototypeSetUint16, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, UINT16_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetInt16, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, INT16_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetUint32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, UINT32_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetInt32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, INT32_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetFloat32, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, FLOAT32_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetFloat64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, FLOAT64_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetBigUint64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, BIGUINT64_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TF_BUILTIN(DataViewPrototypeSetBigInt64, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp7}, TNode<RawPtrT>{tmp8}, TNode<IntPtrT>{tmp9}}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<NativeContext> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp28}, TNode<RawPtrT>{tmp29}, TNode<IntPtrT>{tmp30}}, TNode<IntPtrT>{tmp34});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Oddball> tmp42;
    USE(tmp42);
    tmp42 = Undefined_0(state_);
    ca_.Goto(&block7, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<NativeContext> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    ca_.Bind(&block7, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block9, &block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp52}, TNode<RawPtrT>{tmp53}, TNode<IntPtrT>{tmp54}}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block11, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp60);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Oddball> tmp68;
    USE(tmp68);
    tmp68 = Undefined_0(state_);
    ca_.Goto(&block11, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp69;
    TNode<RawPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block11, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = DataViewSet_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp73}, TNode<Object>{tmp74}, TNode<Object>{tmp75}, TNode<Object>{tmp76}, BIGINT64_ELEMENTS);
    arguments.PopAndReturn(tmp77);
  }
}

TNode<JSDataView> Cast_JSDataView_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSDataView> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSDataView> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSDataView> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSDataView_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSDataView> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSDataView> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSDataView>{tmp20};
}

}  // namespace internal
}  // namespace v8

