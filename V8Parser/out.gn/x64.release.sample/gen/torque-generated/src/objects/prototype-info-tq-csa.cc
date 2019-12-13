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

TNode<Map> kPrototypeInfoMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).PrototypeInfoMapConstant();
return TNode<Map>{tmp0};
}

TNode<PrototypeInfo> Cast_PrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, PrototypeInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp1);
    TNode<Map>tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = kPrototypeInfoMap_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<HeapObject> tmp5;
    ca_.Bind(&block3, &tmp5);
    ca_.Goto(label_CastError);
  }

  if (block4.is_used()) {
    TNode<HeapObject> tmp6;
    ca_.Bind(&block4, &tmp6);
    TNode<PrototypeInfo> tmp7;
    USE(tmp7);
    tmp7 = TORQUE_CAST(TNode<HeapObject>{tmp6});
    ca_.Goto(&block5, tmp6, tmp7);
  }

    TNode<HeapObject> tmp8;
    TNode<PrototypeInfo> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<PrototypeInfo>{tmp9};
}

TNode<HeapObject> LoadPrototypeInfoJsModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kJsModuleNamespaceOffset);
    USE(tmp1);
    TNode<HeapObject>tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<HeapObject>{tmp4};
}

void StorePrototypeInfoJsModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<HeapObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kJsModuleNamespaceOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<HeapObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadPrototypeInfoPrototypeUsers_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kPrototypeUsersOffset);
    USE(tmp1);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StorePrototypeInfoPrototypeUsers_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kPrototypeUsersOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadPrototypeInfoRegistrySlot_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kRegistrySlotOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StorePrototypeInfoRegistrySlot_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kRegistrySlotOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Object> LoadPrototypeInfoValidityCell_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kValidityCellOffset);
    USE(tmp1);
    TNode<Object>tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Object>{tmp4};
}

void StorePrototypeInfoValidityCell_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kValidityCellOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<MaybeObject> LoadPrototypeInfoObjectCreateMap_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, MaybeObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kObjectCreateMapOffset);
    USE(tmp1);
    TNode<MaybeObject>tmp2 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<MaybeObject>{tmp4};
}

void StorePrototypeInfoObjectCreateMap_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<MaybeObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, MaybeObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, MaybeObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<MaybeObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kObjectCreateMapOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<MaybeObject> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadPrototypeInfoBitField_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(PrototypeInfo::kBitFieldOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StorePrototypeInfoBitField_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PrototypeInfo, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<PrototypeInfo> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(PrototypeInfo::kBitFieldOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<PrototypeInfo> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

}  // namespace internal
}  // namespace v8

