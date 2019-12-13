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

TNode<PrototypeInfo> LoadMapPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_m, compiler::CodeAssemblerLabel* label_HasNoPrototypeInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Map, PrototypeInfo> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, PrototypeInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_m);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<PrototypeInfo> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Method_Map_PrototypeInfo_0(state_, TNode<Map>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Map> tmp2;
    TNode<Map> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_HasNoPrototypeInfo);
  }

  if (block3.is_used()) {
    TNode<Map> tmp4;
    TNode<Map> tmp5;
    TNode<PrototypeInfo> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Map> tmp7;
    TNode<PrototypeInfo> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<PrototypeInfo>{tmp8};
}

TNode<Uint8T> LoadMapInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kInstanceSizeInWordsOffset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kInstanceSizeInWordsOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadMapInObjectPropertiesStartOrConstructorFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kInObjectPropertiesStartOrConstructorFunctionIndexOffset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapInObjectPropertiesStartOrConstructorFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kInObjectPropertiesStartOrConstructorFunctionIndexOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadMapUsedOrUnusedInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kUsedOrUnusedInstanceSizeInWordsOffset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapUsedOrUnusedInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kUsedOrUnusedInstanceSizeInWordsOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadMapVisitorId_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kVisitorIdOffset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapVisitorId_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kVisitorIdOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint16T> LoadMapInstanceType_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint16T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kInstanceTypeOffset);
    USE(tmp1);
    TNode<Uint16T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint16T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint16T>{tmp4};
}

void StoreMapInstanceType_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint16T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint16T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint16T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint16T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kInstanceTypeOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint16T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadMapBitField_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kBitFieldOffset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapBitField_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kBitFieldOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint8T> LoadMapBitField2_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kBitField2Offset);
    USE(tmp1);
    TNode<Uint8T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint8T>{tmp4};
}

void StoreMapBitField2_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint8T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint8T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kBitField2Offset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint8T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Uint32T> LoadMapBitField3_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kBitField3Offset);
    USE(tmp1);
    TNode<Uint32T>tmp2 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Uint32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Uint32T>{tmp4};
}

void StoreMapBitField3_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Uint32T> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kBitField3Offset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Uint32T> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<HeapObject> LoadMapPrototype_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kPrototypeOffset);
    USE(tmp1);
    TNode<HeapObject>tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<HeapObject>{tmp4};
}

void StoreMapPrototype_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<HeapObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kPrototypeOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadMapConstructorOrBackPointerOrNativeContext_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kConstructorOrBackPointerOrNativeContextOffset);
    USE(tmp1);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StoreMapConstructorOrBackPointerOrNativeContext_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kConstructorOrBackPointerOrNativeContextOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<DescriptorArray> LoadMapInstanceDescriptors_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, DescriptorArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kInstanceDescriptorsOffset);
    USE(tmp1);
    TNode<DescriptorArray>tmp2 = CodeStubAssembler(state_).LoadReference<DescriptorArray>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<DescriptorArray> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<DescriptorArray>{tmp4};
}

void StoreMapInstanceDescriptors_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<DescriptorArray> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, DescriptorArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, DescriptorArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<DescriptorArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kInstanceDescriptorsOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<DescriptorArray> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<WeakFixedArray> LoadMapDependentCode_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, WeakFixedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kDependentCodeOffset);
    USE(tmp1);
    TNode<WeakFixedArray>tmp2 = CodeStubAssembler(state_).LoadReference<WeakFixedArray>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<WeakFixedArray> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<WeakFixedArray>{tmp4};
}

void StoreMapDependentCode_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<WeakFixedArray> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, WeakFixedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, WeakFixedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<WeakFixedArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kDependentCodeOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<WeakFixedArray> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadMapPrototypeValidityCell_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kPrototypeValidityCellOffset);
    USE(tmp1);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StoreMapPrototypeValidityCell_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kPrototypeValidityCellOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<MaybeObject> LoadMapTransitionsOrPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kTransitionsOrPrototypeInfoOffset);
    USE(tmp1);
    TNode<MaybeObject>tmp2 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Map> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<MaybeObject>{tmp4};
}

void StoreMapTransitionsOrPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<MaybeObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    TNode<MaybeObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(Map::kTransitionsOrPrototypeInfoOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Map> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<PrototypeInfo> Method_Map_PrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_this, compiler::CodeAssemblerLabel* label_HasNoPrototypeInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, MaybeObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, MaybeObject, MaybeObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, Object, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, MaybeObject, HeapObject, PrototypeInfo> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map, PrototypeInfo> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<Map> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(Map::kTransitionsOrPrototypeInfoOffset);
    USE(tmp1);
    TNode<MaybeObject>tmp2 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<MaybeObject> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_Weak_Map_0(state_, TNode<MaybeObject>{tmp2}, &label0);
    ca_.Goto(&block5, tmp0, tmp2, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp2, tmp2);
    }
  }

  if (block6.is_used()) {
    TNode<Map> tmp4;
    TNode<MaybeObject> tmp5;
    TNode<MaybeObject> tmp6;
    ca_.Bind(&block6, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_Smi_0(state_, TNode<Object>{ca_.UncheckedCast<Object>(tmp5)}, &label0);
    ca_.Goto(&block9, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5));
    }
  }

  if (block5.is_used()) {
    TNode<Map> tmp8;
    TNode<MaybeObject> tmp9;
    TNode<MaybeObject> tmp10;
    TNode<MaybeObject> tmp11;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    TNode<Map> tmp12;
    TNode<MaybeObject> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block10, &tmp12, &tmp13, &tmp14);
    TNode<PrototypeInfo> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_PrototypeInfo_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp13)}, &label0);
    ca_.Goto(&block13, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13), tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13));
    }
  }

  if (block9.is_used()) {
    TNode<Map> tmp16;
    TNode<MaybeObject> tmp17;
    TNode<Object> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block9, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    TNode<Map> tmp20;
    TNode<MaybeObject> tmp21;
    TNode<HeapObject> tmp22;
    ca_.Bind(&block14, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block1);
  }

  if (block13.is_used()) {
    TNode<Map> tmp23;
    TNode<MaybeObject> tmp24;
    TNode<HeapObject> tmp25;
    TNode<PrototypeInfo> tmp26;
    ca_.Bind(&block13, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block15, tmp23, tmp26);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_HasNoPrototypeInfo);
  }

    TNode<Map> tmp27;
    TNode<PrototypeInfo> tmp28;
    ca_.Bind(&block15, &tmp27, &tmp28);
  return TNode<PrototypeInfo>{tmp28};
}

TNode<MaybeObject> Cast_Weak_Map_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<MaybeObject, MaybeObject> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<MaybeObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsWeakOrCleared(TNode<MaybeObject>{tmp0});
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
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
    TNode<MaybeObject> tmp5;
    USE(tmp5);
    tmp5 = (TNode<MaybeObject>{tmp4});
    ca_.Goto(&block5, tmp4, tmp5);
  }

    TNode<MaybeObject> tmp6;
    TNode<MaybeObject> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
  return TNode<MaybeObject>{tmp7};
}

}  // namespace internal
}  // namespace v8

