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

TNode<JSTypedArray> AllocateTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_isOnHeap, TNode<Map> p_map, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_byteOffset, TNode<UintPtrT> p_byteLength, TNode<UintPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, UintPtrT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, UintPtrT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, UintPtrT, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, JSTypedArray> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, JSTypedArray> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, JSTypedArray> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, JSTypedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, ByteArray, JSTypedArray> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, UintPtrT, UintPtrT, UintPtrT, JSTypedArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_buffer, p_byteOffset, p_byteLength, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<JSArrayBuffer> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<UintPtrT> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    if ((p_isOnHeap)) {
      ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, ca_.Uninitialized<ByteArray>());
    } else {
      ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, ca_.Uninitialized<ByteArray>());
    }
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Map> tmp7;
    TNode<JSArrayBuffer> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<ByteArray> tmp12;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<ByteArray> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).AllocateByteArray(TNode<UintPtrT>{tmp10});
    ca_.Goto(&block4, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block3.is_used()) {
    TNode<Context> tmp14;
    TNode<Map> tmp15;
    TNode<JSArrayBuffer> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<ByteArray> tmp20;
    ca_.Bind(&block3, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<ByteArray> tmp21;
    USE(tmp21);
    tmp21 = kEmptyByteArray_0(state_);
    TNode<IntPtrT> tmp22 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp22);
    TNode<RawPtrT>tmp23 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp16, tmp22});
    TNode<UintPtrT> tmp24;
    USE(tmp24);
    tmp24 = Convert_uintptr_RawPtr_0(state_, TNode<RawPtrT>{tmp23});
    ca_.Goto(&block4, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp21);
  }

  if (block9.is_used()) {
    TNode<Context> tmp25;
    TNode<Map> tmp26;
    TNode<JSArrayBuffer> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<UintPtrT> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<ByteArray> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block9, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34);
  }

  if (block10.is_used()) {
    TNode<Context> tmp35;
    TNode<Map> tmp36;
    TNode<JSArrayBuffer> tmp37;
    TNode<UintPtrT> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<ByteArray> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<BoolT> tmp43;
    ca_.Bind(&block10, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<UintPtrT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp42}, TNode<UintPtrT>{tmp38});
    TNode<BoolT> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp44}, TNode<UintPtrT>{tmp42});
    ca_.Goto(&block11, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp45);
  }

  if (block11.is_used()) {
    TNode<Context> tmp46;
    TNode<Map> tmp47;
    TNode<JSArrayBuffer> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<UintPtrT> tmp51;
    TNode<ByteArray> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<BoolT> tmp54;
    TNode<BoolT> tmp55;
    ca_.Bind(&block11, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Branch(tmp55, &block7, &block8, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53);
  }

  if (block8.is_used()) {
    TNode<Context> tmp56;
    TNode<Map> tmp57;
    TNode<JSArrayBuffer> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<ByteArray> tmp62;
    TNode<UintPtrT> tmp63;
    ca_.Bind(&block8, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsMockArrayBufferAllocatorFlag() || (backingStore + byteOffset) >= backingStore' failed", "src/builtins/typed-array-createtypedarray.tq", 43);
  }

  if (block7.is_used()) {
    TNode<Context> tmp64;
    TNode<Map> tmp65;
    TNode<JSArrayBuffer> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<UintPtrT> tmp68;
    TNode<UintPtrT> tmp69;
    TNode<ByteArray> tmp70;
    TNode<UintPtrT> tmp71;
    ca_.Bind(&block7, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
  }

  if (block4.is_used()) {
    TNode<Context> tmp72;
    TNode<Map> tmp73;
    TNode<JSArrayBuffer> tmp74;
    TNode<UintPtrT> tmp75;
    TNode<UintPtrT> tmp76;
    TNode<UintPtrT> tmp77;
    TNode<ByteArray> tmp78;
    ca_.Bind(&block4, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<JSObject> tmp79;
    USE(tmp79);
    tmp79 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{tmp72}, TNode<Map>{tmp73});
    TNode<JSTypedArray> tmp80;
    USE(tmp80);
    tmp80 = UnsafeCast_JSTypedArray_0(state_, TNode<Context>{tmp72}, TNode<Object>{tmp79});
    TNode<IntPtrT> tmp81 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp81);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp80, tmp81}, tmp78);
    TNode<IntPtrT> tmp82 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp82);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp80, tmp82}, tmp74);
    TNode<IntPtrT> tmp83 = ca_.IntPtrConstant(JSArrayBufferView::kByteOffsetOffset);
    USE(tmp83);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp80, tmp83}, tmp75);
    TNode<IntPtrT> tmp84 = ca_.IntPtrConstant(JSArrayBufferView::kByteLengthOffset);
    USE(tmp84);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp80, tmp84}, tmp76);
    TNode<IntPtrT> tmp85 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp85);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp80, tmp85}, tmp77);
    if ((p_isOnHeap)) {
      ca_.Goto(&block12, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp80);
    } else {
      ca_.Goto(&block13, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp80);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp86;
    TNode<Map> tmp87;
    TNode<JSArrayBuffer> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<UintPtrT> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<ByteArray> tmp92;
    TNode<JSTypedArray> tmp93;
    ca_.Bind(&block12, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOnHeapDataPtr(TNode<JSTypedArray>{tmp93}, TNode<ByteArray>{tmp92}, TNode<UintPtrT>{tmp89});
    ca_.Goto(&block14, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93);
  }

  if (block13.is_used()) {
    TNode<Context> tmp94;
    TNode<Map> tmp95;
    TNode<JSArrayBuffer> tmp96;
    TNode<UintPtrT> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<ByteArray> tmp100;
    TNode<JSTypedArray> tmp101;
    ca_.Bind(&block13, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    TNode<IntPtrT> tmp102 = ca_.IntPtrConstant(JSArrayBuffer::kBackingStoreOffset);
    USE(tmp102);
    TNode<RawPtrT>tmp103 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp96, tmp102});
    TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOffHeapDataPtr(TNode<JSTypedArray>{tmp101}, TNode<RawPtrT>{tmp103}, TNode<UintPtrT>{tmp97});
    ca_.Goto(&block14, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
  }

  if (block18.is_used()) {
    TNode<Context> tmp104;
    TNode<Map> tmp105;
    TNode<JSArrayBuffer> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<UintPtrT> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<ByteArray> tmp110;
    TNode<JSTypedArray> tmp111;
    ca_.Bind(&block18, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111);
    CodeStubAssembler(state_).FailAssert("Torque assert 'typedArray.data_ptr == (buffer.backing_store + Convert<intptr>(byteOffset))' failed", "src/builtins/typed-array-createtypedarray.tq", 64);
  }

  if (block17.is_used()) {
    TNode<Context> tmp112;
    TNode<Map> tmp113;
    TNode<JSArrayBuffer> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<UintPtrT> tmp116;
    TNode<UintPtrT> tmp117;
    TNode<ByteArray> tmp118;
    TNode<JSTypedArray> tmp119;
    ca_.Bind(&block17, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119);
  }

  if (block14.is_used()) {
    TNode<Context> tmp120;
    TNode<Map> tmp121;
    TNode<JSArrayBuffer> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<UintPtrT> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<ByteArray> tmp126;
    TNode<JSTypedArray> tmp127;
    ca_.Bind(&block14, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    TypedArrayBuiltinsAssembler(state_).SetupTypedArrayEmbedderFields(TNode<JSTypedArray>{tmp127});
    ca_.Goto(&block19, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp127);
  }

    TNode<Context> tmp128;
    TNode<Map> tmp129;
    TNode<JSArrayBuffer> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<UintPtrT> tmp133;
    TNode<JSTypedArray> tmp134;
    ca_.Bind(&block19, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
  return TNode<JSTypedArray>{tmp134};
}

TNode<JSTypedArray> TypedArrayInitialize_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_initialize, TNode<Map> p_map, TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo, TNode<JSReceiver> p_bufferConstructor, compiler::CodeAssemblerLabel* label_IfRangeError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Int32T, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Int32T, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, JSArrayBuffer, JSTypedArray> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, JSArrayBuffer, JSTypedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, JSArrayBuffer, JSTypedArray> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, Object, Object, Context> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, UintPtrT, Number, JSReceiver, UintPtrT, Object, Object, Context, JSArrayBuffer> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_length, p_elementsInfo.sizeLog2, p_elementsInfo.kind, p_bufferConstructor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<Int32T> tmp4;
    TNode<JSReceiver> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<UintPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp2}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block4, &block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp3, tmp4, tmp2, tmp2);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Map> tmp9;
    TNode<UintPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<Int32T> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<UintPtrT> tmp14;
    TNode<Int32T> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp18;
    TNode<Map> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<Int32T> tmp22;
    TNode<JSReceiver> tmp23;
    TNode<UintPtrT> tmp24;
    TNode<Int32T> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<UintPtrT> tmp27;
    ca_.Bind(&block5, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<UintPtrT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp28}, TNode<UintPtrT>{tmp24});
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp27}, TNode<UintPtrT>{tmp29});
    ca_.Branch(tmp30, &block6, &block7, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp29);
  }

  if (block6.is_used()) {
    TNode<Context> tmp31;
    TNode<Map> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<Int32T> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<UintPtrT> tmp37;
    TNode<Int32T> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<UintPtrT> tmp41;
    ca_.Bind(&block6, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    TNode<Context> tmp42;
    TNode<Map> tmp43;
    TNode<UintPtrT> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<Int32T> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Int32T> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<UintPtrT> tmp51;
    TNode<UintPtrT> tmp52;
    ca_.Bind(&block7, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<UintPtrT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp51}, TNode<UintPtrT>{tmp48});
    TNode<Number> tmp54;
    USE(tmp54);
    tmp54 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp53});
    TNode<JSReceiver> tmp55;
    USE(tmp55);
    tmp55 = GetArrayBufferFunction_0(state_, TNode<Context>{tmp42});
    TNode<UintPtrT> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp47}, TNode<HeapObject>{tmp55});
    ca_.Branch(tmp57, &block12, &block13, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp53, tmp54, tmp55, tmp56);
  }

  if (block12.is_used()) {
    TNode<Context> tmp58;
    TNode<Map> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<Int32T> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<UintPtrT> tmp64;
    TNode<Number> tmp65;
    TNode<JSReceiver> tmp66;
    TNode<UintPtrT> tmp67;
    ca_.Bind(&block12, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<JSReceiver> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).ConstructWithTarget(TNode<Context>{tmp58}, TNode<JSReceiver>{tmp66}, TNode<JSReceiver>{tmp63}, TNode<Object>{tmp65});
    ca_.Goto(&block9, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68);
  }

  if (block13.is_used()) {
    TNode<Context> tmp69;
    TNode<Map> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<Int32T> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<UintPtrT> tmp75;
    TNode<Number> tmp76;
    TNode<JSReceiver> tmp77;
    TNode<UintPtrT> tmp78;
    ca_.Bind(&block13, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<UintPtrT> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_uintptr_constexpr_int31_0(state_, JSTypedArray::kMaxSizeInHeap);
    TNode<BoolT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp75}, TNode<UintPtrT>{tmp79});
    ca_.Branch(tmp80, &block14, &block15, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78);
  }

  if (block14.is_used()) {
    TNode<Context> tmp81;
    TNode<Map> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<UintPtrT> tmp84;
    TNode<Int32T> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<Number> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<UintPtrT> tmp90;
    ca_.Bind(&block14, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    if ((p_initialize)) {
      ca_.Goto(&block19, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
    } else {
      ca_.Goto(&block20, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp91;
    TNode<Map> tmp92;
    TNode<UintPtrT> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<Int32T> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<UintPtrT> tmp97;
    TNode<Number> tmp98;
    TNode<JSReceiver> tmp99;
    TNode<UintPtrT> tmp100;
    ca_.Bind(&block15, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<JSArrayBuffer> tmp101;
    USE(tmp101);
    tmp101 = TypedArrayBuiltinsAssembler(state_).AllocateEmptyOnHeapBuffer(TNode<Context>{tmp91}, TNode<UintPtrT>{tmp97});
    TNode<JSTypedArray> tmp102;
    USE(tmp102);
    tmp102 = AllocateTypedArray_0(state_, TNode<Context>{tmp91}, true, TNode<Map>{tmp92}, TNode<JSArrayBuffer>{tmp101}, TNode<UintPtrT>{tmp100}, TNode<UintPtrT>{tmp97}, TNode<UintPtrT>{tmp93});
    if ((p_initialize)) {
      ca_.Goto(&block16, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102);
    } else {
      ca_.Goto(&block17, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp103;
    TNode<Map> tmp104;
    TNode<UintPtrT> tmp105;
    TNode<UintPtrT> tmp106;
    TNode<Int32T> tmp107;
    TNode<JSReceiver> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<Number> tmp110;
    TNode<JSReceiver> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<JSArrayBuffer> tmp113;
    TNode<JSTypedArray> tmp114;
    ca_.Bind(&block16, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
    TNode<RawPtrT> tmp115;
    USE(tmp115);
    tmp115 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp114});
    TNode<IntPtrT> tmp116;
    USE(tmp116);
    tmp116 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TypedArrayBuiltinsAssembler(state_).CallCMemset(TNode<RawPtrT>{tmp115}, TNode<IntPtrT>{tmp116}, TNode<UintPtrT>{tmp109});
    ca_.Goto(&block18, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114);
  }

  if (block17.is_used()) {
    TNode<Context> tmp117;
    TNode<Map> tmp118;
    TNode<UintPtrT> tmp119;
    TNode<UintPtrT> tmp120;
    TNode<Int32T> tmp121;
    TNode<JSReceiver> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<Number> tmp124;
    TNode<JSReceiver> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<JSArrayBuffer> tmp127;
    TNode<JSTypedArray> tmp128;
    ca_.Bind(&block17, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    ca_.Goto(&block18, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128);
  }

  if (block18.is_used()) {
    TNode<Context> tmp129;
    TNode<Map> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<Int32T> tmp133;
    TNode<JSReceiver> tmp134;
    TNode<UintPtrT> tmp135;
    TNode<Number> tmp136;
    TNode<JSReceiver> tmp137;
    TNode<UintPtrT> tmp138;
    TNode<JSArrayBuffer> tmp139;
    TNode<JSTypedArray> tmp140;
    ca_.Bind(&block18, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    ca_.Goto(&block2, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp140);
  }

  if (block19.is_used()) {
    TNode<Context> tmp141;
    TNode<Map> tmp142;
    TNode<UintPtrT> tmp143;
    TNode<UintPtrT> tmp144;
    TNode<Int32T> tmp145;
    TNode<JSReceiver> tmp146;
    TNode<UintPtrT> tmp147;
    TNode<Number> tmp148;
    TNode<JSReceiver> tmp149;
    TNode<UintPtrT> tmp150;
    ca_.Bind(&block19, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150);
    TNode<JSReceiver> tmp151;
    USE(tmp151);
    tmp151 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp141}, TNode<JSReceiver>{tmp149}, TNode<Object>{tmp148});
    ca_.Goto(&block9, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151);
  }

  if (block20.is_used()) {
    TNode<Context> tmp152;
    TNode<Map> tmp153;
    TNode<UintPtrT> tmp154;
    TNode<UintPtrT> tmp155;
    TNode<Int32T> tmp156;
    TNode<JSReceiver> tmp157;
    TNode<UintPtrT> tmp158;
    TNode<Number> tmp159;
    TNode<JSReceiver> tmp160;
    TNode<UintPtrT> tmp161;
    ca_.Bind(&block20, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    TNode<JSFunction> tmp162;
    USE(tmp162);
    tmp162 = GetArrayBufferNoInitFunction_0(state_, TNode<Context>{tmp152});
    TNode<Oddball> tmp163;
    USE(tmp163);
    tmp163 = Undefined_0(state_);
    TNode<Object> tmp164;
    USE(tmp164);
    tmp164 = CodeStubAssembler(state_).Call(TNode<Context>{tmp152}, TNode<JSReceiver>{tmp162}, TNode<Object>{tmp163}, TNode<Object>{tmp159});
    ca_.Goto(&block9, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp164);
  }

  if (block9.is_used()) {
    TNode<Context> tmp165;
    TNode<Map> tmp166;
    TNode<UintPtrT> tmp167;
    TNode<UintPtrT> tmp168;
    TNode<Int32T> tmp169;
    TNode<JSReceiver> tmp170;
    TNode<UintPtrT> tmp171;
    TNode<Number> tmp172;
    TNode<JSReceiver> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<Object> tmp175;
    ca_.Bind(&block9, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175);
    TNode<JSArrayBuffer> tmp176;
    USE(tmp176);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp176 = Cast_JSArrayBuffer_1(state_, TNode<Context>{tmp165}, TNode<Object>{tmp175}, &label0);
    ca_.Goto(&block24, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp175, tmp165, tmp176);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp175, tmp165);
    }
  }

  if (block25.is_used()) {
    TNode<Context> tmp177;
    TNode<Map> tmp178;
    TNode<UintPtrT> tmp179;
    TNode<UintPtrT> tmp180;
    TNode<Int32T> tmp181;
    TNode<JSReceiver> tmp182;
    TNode<UintPtrT> tmp183;
    TNode<Number> tmp184;
    TNode<JSReceiver> tmp185;
    TNode<UintPtrT> tmp186;
    TNode<Object> tmp187;
    TNode<Object> tmp188;
    TNode<Context> tmp189;
    ca_.Bind(&block25, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block24.is_used()) {
    TNode<Context> tmp190;
    TNode<Map> tmp191;
    TNode<UintPtrT> tmp192;
    TNode<UintPtrT> tmp193;
    TNode<Int32T> tmp194;
    TNode<JSReceiver> tmp195;
    TNode<UintPtrT> tmp196;
    TNode<Number> tmp197;
    TNode<JSReceiver> tmp198;
    TNode<UintPtrT> tmp199;
    TNode<Object> tmp200;
    TNode<Object> tmp201;
    TNode<Context> tmp202;
    TNode<JSArrayBuffer> tmp203;
    ca_.Bind(&block24, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203);
    TNode<JSTypedArray> tmp204;
    USE(tmp204);
    tmp204 = AllocateTypedArray_0(state_, TNode<Context>{tmp190}, false, TNode<Map>{tmp191}, TNode<JSArrayBuffer>{tmp203}, TNode<UintPtrT>{tmp199}, TNode<UintPtrT>{tmp196}, TNode<UintPtrT>{tmp192});
    ca_.Goto(&block2, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp204);
  }

  if (block2.is_used()) {
    TNode<Context> tmp205;
    TNode<Map> tmp206;
    TNode<UintPtrT> tmp207;
    TNode<UintPtrT> tmp208;
    TNode<Int32T> tmp209;
    TNode<JSReceiver> tmp210;
    TNode<JSTypedArray> tmp211;
    ca_.Bind(&block2, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211);
    ca_.Goto(&block26, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfRangeError);
  }

    TNode<Context> tmp212;
    TNode<Map> tmp213;
    TNode<UintPtrT> tmp214;
    TNode<UintPtrT> tmp215;
    TNode<Int32T> tmp216;
    TNode<JSReceiver> tmp217;
    TNode<JSTypedArray> tmp218;
    ca_.Bind(&block26, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218);
  return TNode<JSTypedArray>{tmp218};
}

TNode<JSTypedArray> ConstructByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<Object> p_lengthObj, TorqueStructTypedArrayElementsInfo p_elementsInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T, Object, Context, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T, UintPtrT, JSReceiver, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T, UintPtrT, JSReceiver, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, Context, JSTypedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, UintPtrT, Int32T, JSTypedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_lengthObj, p_elementsInfo.sizeLog2, p_elementsInfo.kind);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<Object> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<Int32T> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<UintPtrT> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = ToIndex_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp2, tmp0, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp6;
    TNode<Map> tmp7;
    TNode<Object> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<Int32T> tmp10;
    TNode<Object> tmp11;
    TNode<Context> tmp12;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block3, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block4.is_used()) {
    TNode<Context> tmp13;
    TNode<Map> tmp14;
    TNode<Object> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<Int32T> tmp17;
    TNode<Object> tmp18;
    TNode<Context> tmp19;
    TNode<UintPtrT> tmp20;
    ca_.Bind(&block4, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<JSReceiver> tmp21;
    USE(tmp21);
    tmp21 = GetArrayBufferFunction_0(state_, TNode<Context>{tmp13});
    TNode<JSTypedArray> tmp22;
    USE(tmp22);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp22 = TypedArrayInitialize_0(state_, TNode<Context>{tmp13}, true, TNode<Map>{tmp14}, TNode<UintPtrT>{tmp20}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp16}, TNode<Int32T>{tmp17}}, TNode<JSReceiver>{tmp21}, &label0);
    ca_.Goto(&block6, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp21, tmp14, tmp20, tmp16, tmp17, tmp21, tmp13, tmp22);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp21, tmp14, tmp20, tmp16, tmp17, tmp21, tmp13);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp23;
    TNode<Map> tmp24;
    TNode<Object> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<Int32T> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Map> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<Int32T> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Context> tmp35;
    ca_.Bind(&block7, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    ca_.Goto(&block3, tmp23, tmp24, tmp25, tmp26, tmp27);
  }

  if (block6.is_used()) {
    TNode<Context> tmp36;
    TNode<Map> tmp37;
    TNode<Object> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<Int32T> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Map> tmp43;
    TNode<UintPtrT> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<Int32T> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<Context> tmp48;
    TNode<JSTypedArray> tmp49;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    ca_.Goto(&block8, tmp36, tmp37, tmp38, tmp39, tmp40, tmp49);
  }

  if (block3.is_used()) {
    TNode<Context> tmp50;
    TNode<Map> tmp51;
    TNode<Object> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<Int32T> tmp54;
    ca_.Bind(&block3, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp50}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp52});
  }

    TNode<Context> tmp55;
    TNode<Map> tmp56;
    TNode<Object> tmp57;
    TNode<UintPtrT> tmp58;
    TNode<Int32T> tmp59;
    TNode<JSTypedArray> tmp60;
    ca_.Bind(&block8, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
  return TNode<JSTypedArray>{tmp60};
}

TNode<JSTypedArray> ConstructByArrayLike_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<HeapObject> p_arrayLike, TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo, TNode<JSReceiver> p_bufferConstructor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, Map, UintPtrT, UintPtrT, Int32T, JSReceiver, Context, JSTypedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, HeapObject, JSTypedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray, JSTypedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, HeapObject, UintPtrT, UintPtrT, Int32T, JSReceiver, JSTypedArray> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_arrayLike, p_length, p_elementsInfo.sizeLog2, p_elementsInfo.kind, p_bufferConstructor);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<HeapObject> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<Int32T> tmp5;
    TNode<JSReceiver> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<JSTypedArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = TypedArrayInitialize_0(state_, TNode<Context>{tmp0}, false, TNode<Map>{tmp1}, TNode<UintPtrT>{tmp3}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp4}, TNode<Int32T>{tmp5}}, TNode<JSReceiver>{tmp6}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp1, tmp3, tmp4, tmp5, tmp6, tmp0, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp1, tmp3, tmp4, tmp5, tmp6, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<Map> tmp9;
    TNode<HeapObject> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<Int32T> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<Map> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<Int32T> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Context> tmp20;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Number> tmp21;
    USE(tmp21);
    tmp21 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp11});
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp8}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp21});
  }

  if (block4.is_used()) {
    TNode<Context> tmp22;
    TNode<Map> tmp23;
    TNode<HeapObject> tmp24;
    TNode<UintPtrT> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<Int32T> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Map> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<Int32T> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Context> tmp34;
    TNode<JSTypedArray> tmp35;
    ca_.Bind(&block4, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<JSTypedArray> tmp36;
    USE(tmp36);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp36 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{tmp24}, &label0);
    ca_.Goto(&block8, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp35, tmp24, tmp36);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp35, tmp24);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp37;
    TNode<Map> tmp38;
    TNode<HeapObject> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Int32T> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<JSTypedArray> tmp44;
    TNode<HeapObject> tmp45;
    ca_.Bind(&block9, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    ca_.Goto(&block7, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44);
  }

  if (block8.is_used()) {
    TNode<Context> tmp46;
    TNode<Map> tmp47;
    TNode<HeapObject> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<Int32T> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<JSTypedArray> tmp53;
    TNode<HeapObject> tmp54;
    TNode<JSTypedArray> tmp55;
    ca_.Bind(&block8, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<IntPtrT> tmp56 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp56);
    TNode<JSArrayBuffer>tmp57 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp55, tmp56});
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp57});
    ca_.Branch(tmp58, &block10, &block11, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp55);
  }

  if (block10.is_used()) {
    TNode<Context> tmp59;
    TNode<Map> tmp60;
    TNode<HeapObject> tmp61;
    TNode<UintPtrT> tmp62;
    TNode<UintPtrT> tmp63;
    TNode<Int32T> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<JSTypedArray> tmp66;
    TNode<JSTypedArray> tmp67;
    ca_.Bind(&block10, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp59}, MessageTemplate::kDetachedOperation, "Construct");
  }

  if (block11.is_used()) {
    TNode<Context> tmp68;
    TNode<Map> tmp69;
    TNode<HeapObject> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<Int32T> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<JSTypedArray> tmp75;
    TNode<JSTypedArray> tmp76;
    ca_.Bind(&block11, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Int32T> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp76});
    TNode<BoolT> tmp78;
    USE(tmp78);
    tmp78 = ElementsKindNotEqual_0(state_, TNode<Int32T>{tmp77}, TNode<Int32T>{tmp73});
    ca_.Branch(tmp78, &block13, &block14, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76);
  }

  if (block13.is_used()) {
    TNode<Context> tmp79;
    TNode<Map> tmp80;
    TNode<HeapObject> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<Int32T> tmp84;
    TNode<JSReceiver> tmp85;
    TNode<JSTypedArray> tmp86;
    TNode<JSTypedArray> tmp87;
    ca_.Bind(&block13, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
    ca_.Goto(&block7, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86);
  }

  if (block14.is_used()) {
    TNode<Context> tmp88;
    TNode<Map> tmp89;
    TNode<HeapObject> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<Int32T> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<JSTypedArray> tmp95;
    TNode<JSTypedArray> tmp96;
    ca_.Bind(&block14, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96);
    TNode<UintPtrT> tmp97;
    USE(tmp97);
    tmp97 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp91}, TNode<UintPtrT>{tmp97});
    ca_.Branch(tmp98, &block16, &block17, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96);
  }

  if (block16.is_used()) {
    TNode<Context> tmp99;
    TNode<Map> tmp100;
    TNode<HeapObject> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<UintPtrT> tmp103;
    TNode<Int32T> tmp104;
    TNode<JSReceiver> tmp105;
    TNode<JSTypedArray> tmp106;
    TNode<JSTypedArray> tmp107;
    ca_.Bind(&block16, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    TNode<IntPtrT> tmp108 = ca_.IntPtrConstant(JSArrayBufferView::kByteLengthOffset);
    USE(tmp108);
    TNode<UintPtrT>tmp109 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp106, tmp108});
    TNode<RawPtrT> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp106});
    TNode<RawPtrT> tmp111;
    USE(tmp111);
    tmp111 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp107});
    TypedArrayBuiltinsAssembler(state_).CallCMemcpy(TNode<RawPtrT>{tmp110}, TNode<RawPtrT>{tmp111}, TNode<UintPtrT>{tmp109});
    ca_.Goto(&block17, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107);
  }

  if (block21.is_used()) {
    TNode<Context> tmp112;
    TNode<Map> tmp113;
    TNode<HeapObject> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<UintPtrT> tmp116;
    TNode<Int32T> tmp117;
    TNode<JSReceiver> tmp118;
    TNode<JSTypedArray> tmp119;
    TNode<JSTypedArray> tmp120;
    TNode<UintPtrT> tmp121;
    ca_.Bind(&block21, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    CodeStubAssembler(state_).FailAssert("Torque assert 'byteLength <= kArrayBufferMaxByteLength' failed", "src/builtins/typed-array-createtypedarray.tq", 161);
  }

  if (block20.is_used()) {
    TNode<Context> tmp122;
    TNode<Map> tmp123;
    TNode<HeapObject> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<Int32T> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<JSTypedArray> tmp129;
    TNode<JSTypedArray> tmp130;
    TNode<UintPtrT> tmp131;
    ca_.Bind(&block20, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
  }

  if (block17.is_used()) {
    TNode<Context> tmp132;
    TNode<Map> tmp133;
    TNode<HeapObject> tmp134;
    TNode<UintPtrT> tmp135;
    TNode<UintPtrT> tmp136;
    TNode<Int32T> tmp137;
    TNode<JSReceiver> tmp138;
    TNode<JSTypedArray> tmp139;
    TNode<JSTypedArray> tmp140;
    ca_.Bind(&block17, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    ca_.Goto(&block6, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139);
  }

  if (block7.is_used()) {
    TNode<Context> tmp141;
    TNode<Map> tmp142;
    TNode<HeapObject> tmp143;
    TNode<UintPtrT> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<Int32T> tmp146;
    TNode<JSReceiver> tmp147;
    TNode<JSTypedArray> tmp148;
    ca_.Bind(&block7, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    TNode<UintPtrT> tmp149;
    USE(tmp149);
    tmp149 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp150;
    USE(tmp150);
    tmp150 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp144}, TNode<UintPtrT>{tmp149});
    ca_.Branch(tmp150, &block22, &block23, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148);
  }

  if (block22.is_used()) {
    TNode<Context> tmp151;
    TNode<Map> tmp152;
    TNode<HeapObject> tmp153;
    TNode<UintPtrT> tmp154;
    TNode<UintPtrT> tmp155;
    TNode<Int32T> tmp156;
    TNode<JSReceiver> tmp157;
    TNode<JSTypedArray> tmp158;
    ca_.Bind(&block22, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158);
    TNode<Number> tmp159;
    USE(tmp159);
    tmp159 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp154});
    CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArrayCopyElements, tmp151, tmp158, tmp153, tmp159);
    ca_.Goto(&block23, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158);
  }

  if (block23.is_used()) {
    TNode<Context> tmp161;
    TNode<Map> tmp162;
    TNode<HeapObject> tmp163;
    TNode<UintPtrT> tmp164;
    TNode<UintPtrT> tmp165;
    TNode<Int32T> tmp166;
    TNode<JSReceiver> tmp167;
    TNode<JSTypedArray> tmp168;
    ca_.Bind(&block23, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    ca_.Goto(&block6, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168);
  }

  if (block6.is_used()) {
    TNode<Context> tmp169;
    TNode<Map> tmp170;
    TNode<HeapObject> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<Int32T> tmp174;
    TNode<JSReceiver> tmp175;
    TNode<JSTypedArray> tmp176;
    ca_.Bind(&block6, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176);
    ca_.Goto(&block24, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
  }

    TNode<Context> tmp177;
    TNode<Map> tmp178;
    TNode<HeapObject> tmp179;
    TNode<UintPtrT> tmp180;
    TNode<UintPtrT> tmp181;
    TNode<Int32T> tmp182;
    TNode<JSReceiver> tmp183;
    TNode<JSTypedArray> tmp184;
    ca_.Bind(&block24, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184);
  return TNode<JSTypedArray>{tmp184};
}

void ConstructByIterable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_iterable, TNode<JSReceiver> p_iteratorFn, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSArray>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_iterable, p_iteratorFn);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<JSReceiver> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSArray> tmp3;
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kIterableToListMayPreserveHoles, tmp0, tmp1, tmp2));
    USE(tmp3);
    TNode<UintPtrT> tmp4;
    USE(tmp4);
    tmp4 = LoadJSArrayLengthAsUintPtr_0(state_, TNode<JSArray>{tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = GetArrayBufferFunction_0(state_, TNode<Context>{tmp0});
    *label_IfConstructByArrayLike_parameter_2 = tmp5;
    *label_IfConstructByArrayLike_parameter_1 = tmp4;
    *label_IfConstructByArrayLike_parameter_0 = tmp3;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

void ConstructByTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_srcTypedArray, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSTypedArray>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer, UintPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, JSArrayBuffer, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_srcTypedArray);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    tmp2 = GetArrayBufferFunction_0(state_, TNode<Context>{tmp0});
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp3);
    TNode<JSArrayBuffer>tmp4 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp0, tmp1, tmp2, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<JSTypedArray> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<JSArrayBuffer> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSTypedArray> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<JSArrayBuffer> tmp14;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp15);
    TNode<UintPtrT>tmp16 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp12, tmp15});
    ca_.Goto(&block4, tmp11, tmp12, tmp13, tmp14, tmp16);
  }

  if (block4.is_used()) {
    TNode<Context> tmp17;
    TNode<JSTypedArray> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<JSArrayBuffer> tmp20;
    TNode<UintPtrT> tmp21;
    ca_.Bind(&block4, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = TypedArrayBuiltinsAssembler(state_).IsSharedArrayBuffer(TNode<JSArrayBuffer>{tmp20});
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp22});
    ca_.Branch(tmp23, &block6, &block7, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block6.is_used()) {
    TNode<Context> tmp24;
    TNode<JSTypedArray> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<JSArrayBuffer> tmp27;
    TNode<UintPtrT> tmp28;
    ca_.Bind(&block6, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<JSReceiver> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{tmp24}, TNode<Object>{tmp27}, TNode<JSReceiver>{tmp26});
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp27});
    ca_.Branch(tmp30, &block8, &block9, tmp24, tmp25, tmp29, tmp27, tmp28);
  }

  if (block8.is_used()) {
    TNode<Context> tmp31;
    TNode<JSTypedArray> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<JSArrayBuffer> tmp34;
    TNode<UintPtrT> tmp35;
    ca_.Bind(&block8, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<UintPtrT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block9, tmp31, tmp32, tmp33, tmp34, tmp36);
  }

  if (block9.is_used()) {
    TNode<Context> tmp37;
    TNode<JSTypedArray> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<JSArrayBuffer> tmp40;
    TNode<UintPtrT> tmp41;
    ca_.Bind(&block9, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    ca_.Goto(&block7, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block7.is_used()) {
    TNode<Context> tmp42;
    TNode<JSTypedArray> tmp43;
    TNode<JSReceiver> tmp44;
    TNode<JSArrayBuffer> tmp45;
    TNode<UintPtrT> tmp46;
    ca_.Bind(&block7, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    *label_IfConstructByArrayLike_parameter_2 = tmp44;
    *label_IfConstructByArrayLike_parameter_1 = tmp46;
    *label_IfConstructByArrayLike_parameter_0 = tmp43;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

TNode<JSTypedArray> ConstructByArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<JSArrayBuffer> p_buffer, TNode<Object> p_byteOffset, TNode<Object> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, Object, Context> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, Object, Context, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, Object, Context> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, Object, Context, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT, BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, String> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, JSArrayBuffer, Object, Object, UintPtrT, Int32T, JSTypedArray> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map, p_buffer, p_byteOffset, p_length, p_elementsInfo.sizeLog2, p_elementsInfo.kind);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<JSArrayBuffer> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<UintPtrT> tmp5;
    TNode<Int32T> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = ToIndex_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block8, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp3, tmp0, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp3, tmp0);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp8;
    TNode<Map> tmp9;
    TNode<JSArrayBuffer> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<UintPtrT> tmp13;
    TNode<Int32T> tmp14;
    TNode<Object> tmp15;
    TNode<Context> tmp16;
    ca_.Bind(&block9, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block3, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block8.is_used()) {
    TNode<Context> tmp17;
    TNode<Map> tmp18;
    TNode<JSArrayBuffer> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<UintPtrT> tmp22;
    TNode<Int32T> tmp23;
    TNode<Object> tmp24;
    TNode<Context> tmp25;
    TNode<UintPtrT> tmp26;
    ca_.Bind(&block8, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp27}, TNode<UintPtrT>{tmp22});
    TNode<UintPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp28}, TNode<UintPtrT>{tmp29});
    TNode<UintPtrT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT>{tmp26}, TNode<UintPtrT>{tmp30});
    TNode<UintPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT>{tmp31}, TNode<UintPtrT>{tmp32});
    ca_.Branch(tmp33, &block10, &block11, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp26);
  }

  if (block10.is_used()) {
    TNode<Context> tmp34;
    TNode<Map> tmp35;
    TNode<JSArrayBuffer> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<Int32T> tmp40;
    TNode<UintPtrT> tmp41;
    ca_.Bind(&block10, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<String> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_String_constexpr_string_0(state_, "start offset");
    ca_.Goto(&block7, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp42);
  }

  if (block11.is_used()) {
    TNode<Context> tmp43;
    TNode<Map> tmp44;
    TNode<JSArrayBuffer> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<Int32T> tmp49;
    TNode<UintPtrT> tmp50;
    ca_.Bind(&block11, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<UintPtrT> tmp51;
    USE(tmp51);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp51 = ToIndex_0(state_, TNode<Context>{tmp43}, TNode<Object>{tmp47}, &label0);
    ca_.Goto(&block13, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp47, tmp43, tmp51);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp47, tmp43);
    }
  }

  if (block14.is_used()) {
    TNode<Context> tmp52;
    TNode<Map> tmp53;
    TNode<JSArrayBuffer> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<Int32T> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<Object> tmp60;
    TNode<Context> tmp61;
    ca_.Bind(&block14, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block5, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58);
  }

  if (block13.is_used()) {
    TNode<Context> tmp62;
    TNode<Map> tmp63;
    TNode<JSArrayBuffer> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<Int32T> tmp68;
    TNode<UintPtrT> tmp69;
    TNode<Object> tmp70;
    TNode<Context> tmp71;
    TNode<UintPtrT> tmp72;
    ca_.Bind(&block13, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<BoolT> tmp73;
    USE(tmp73);
    tmp73 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp64});
    ca_.Branch(tmp73, &block15, &block16, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp72, ca_.Uninitialized<UintPtrT>());
  }

  if (block15.is_used()) {
    TNode<Context> tmp74;
    TNode<Map> tmp75;
    TNode<JSArrayBuffer> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<UintPtrT> tmp79;
    TNode<Int32T> tmp80;
    TNode<UintPtrT> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<UintPtrT> tmp83;
    ca_.Bind(&block15, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp74}, MessageTemplate::kDetachedOperation, "Construct");
  }

  if (block16.is_used()) {
    TNode<Context> tmp84;
    TNode<Map> tmp85;
    TNode<JSArrayBuffer> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<Int32T> tmp90;
    TNode<UintPtrT> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<UintPtrT> tmp93;
    ca_.Bind(&block16, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    TNode<IntPtrT> tmp94 = ca_.IntPtrConstant(JSArrayBuffer::kByteLengthOffset);
    USE(tmp94);
    TNode<UintPtrT>tmp95 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp86, tmp94});
    TNode<Oddball> tmp96;
    USE(tmp96);
    tmp96 = Undefined_0(state_);
    TNode<BoolT> tmp97;
    USE(tmp97);
    tmp97 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp88}, TNode<HeapObject>{tmp96});
    ca_.Branch(tmp97, &block17, &block18, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp95);
  }

  if (block17.is_used()) {
    TNode<Context> tmp98;
    TNode<Map> tmp99;
    TNode<JSArrayBuffer> tmp100;
    TNode<Object> tmp101;
    TNode<Object> tmp102;
    TNode<UintPtrT> tmp103;
    TNode<Int32T> tmp104;
    TNode<UintPtrT> tmp105;
    TNode<UintPtrT> tmp106;
    TNode<UintPtrT> tmp107;
    TNode<UintPtrT> tmp108;
    ca_.Bind(&block17, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<UintPtrT> tmp109;
    USE(tmp109);
    tmp109 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp109}, TNode<UintPtrT>{tmp103});
    TNode<UintPtrT> tmp111;
    USE(tmp111);
    tmp111 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp112;
    USE(tmp112);
    tmp112 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp110}, TNode<UintPtrT>{tmp111});
    TNode<UintPtrT> tmp113;
    USE(tmp113);
    tmp113 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT>{tmp108}, TNode<UintPtrT>{tmp112});
    TNode<UintPtrT> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp115;
    USE(tmp115);
    tmp115 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT>{tmp113}, TNode<UintPtrT>{tmp114});
    ca_.Branch(tmp115, &block20, &block21, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108);
  }

  if (block20.is_used()) {
    TNode<Context> tmp116;
    TNode<Map> tmp117;
    TNode<JSArrayBuffer> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<Int32T> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<UintPtrT> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<UintPtrT> tmp126;
    ca_.Bind(&block20, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126);
    TNode<String> tmp127;
    USE(tmp127);
    tmp127 = FromConstexpr_String_constexpr_string_0(state_, "byte length");
    ca_.Goto(&block7, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp127);
  }

  if (block21.is_used()) {
    TNode<Context> tmp128;
    TNode<Map> tmp129;
    TNode<JSArrayBuffer> tmp130;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    TNode<UintPtrT> tmp133;
    TNode<Int32T> tmp134;
    TNode<UintPtrT> tmp135;
    TNode<UintPtrT> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<UintPtrT> tmp138;
    ca_.Bind(&block21, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    TNode<BoolT> tmp139;
    USE(tmp139);
    tmp139 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp138}, TNode<UintPtrT>{tmp135});
    ca_.Branch(tmp139, &block23, &block24, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138);
  }

  if (block23.is_used()) {
    TNode<Context> tmp140;
    TNode<Map> tmp141;
    TNode<JSArrayBuffer> tmp142;
    TNode<Object> tmp143;
    TNode<Object> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<Int32T> tmp146;
    TNode<UintPtrT> tmp147;
    TNode<UintPtrT> tmp148;
    TNode<UintPtrT> tmp149;
    TNode<UintPtrT> tmp150;
    ca_.Bind(&block23, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150);
    ca_.Goto(&block3, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146);
  }

  if (block24.is_used()) {
    TNode<Context> tmp151;
    TNode<Map> tmp152;
    TNode<JSArrayBuffer> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<UintPtrT> tmp156;
    TNode<Int32T> tmp157;
    TNode<UintPtrT> tmp158;
    TNode<UintPtrT> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<UintPtrT> tmp161;
    ca_.Bind(&block24, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161);
    TNode<UintPtrT> tmp162;
    USE(tmp162);
    tmp162 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp161}, TNode<UintPtrT>{tmp158});
    TNode<UintPtrT> tmp163;
    USE(tmp163);
    tmp163 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp162}, TNode<UintPtrT>{tmp156});
    TNode<UintPtrT> tmp164;
    USE(tmp164);
    tmp164 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp163}, TNode<UintPtrT>{tmp164});
    ca_.Branch(tmp165, &block26, &block27, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp162, tmp161, tmp156, tmp157, tmp162, tmp162, tmp163);
  }

  if (block26.is_used()) {
    TNode<Context> tmp166;
    TNode<Map> tmp167;
    TNode<JSArrayBuffer> tmp168;
    TNode<Object> tmp169;
    TNode<Object> tmp170;
    TNode<UintPtrT> tmp171;
    TNode<Int32T> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<UintPtrT> tmp175;
    TNode<UintPtrT> tmp176;
    TNode<UintPtrT> tmp177;
    TNode<Int32T> tmp178;
    TNode<UintPtrT> tmp179;
    TNode<UintPtrT> tmp180;
    TNode<UintPtrT> tmp181;
    ca_.Bind(&block26, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181);
    ca_.Goto(&block3, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172);
  }

  if (block27.is_used()) {
    TNode<Context> tmp182;
    TNode<Map> tmp183;
    TNode<JSArrayBuffer> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp186;
    TNode<UintPtrT> tmp187;
    TNode<Int32T> tmp188;
    TNode<UintPtrT> tmp189;
    TNode<UintPtrT> tmp190;
    TNode<UintPtrT> tmp191;
    TNode<UintPtrT> tmp192;
    TNode<UintPtrT> tmp193;
    TNode<Int32T> tmp194;
    TNode<UintPtrT> tmp195;
    TNode<UintPtrT> tmp196;
    TNode<UintPtrT> tmp197;
    ca_.Bind(&block27, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197);
    ca_.Goto(&block19, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp197, tmp191, tmp192);
  }

  if (block18.is_used()) {
    TNode<Context> tmp198;
    TNode<Map> tmp199;
    TNode<JSArrayBuffer> tmp200;
    TNode<Object> tmp201;
    TNode<Object> tmp202;
    TNode<UintPtrT> tmp203;
    TNode<Int32T> tmp204;
    TNode<UintPtrT> tmp205;
    TNode<UintPtrT> tmp206;
    TNode<UintPtrT> tmp207;
    TNode<UintPtrT> tmp208;
    ca_.Bind(&block18, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208);
    TNode<UintPtrT> tmp209;
    USE(tmp209);
    tmp209 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp210;
    USE(tmp210);
    tmp210 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp206}, TNode<UintPtrT>{tmp209});
    ca_.Branch(tmp210, &block29, &block30, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp203, tmp204, tmp206, tmp206);
  }

  if (block29.is_used()) {
    TNode<Context> tmp211;
    TNode<Map> tmp212;
    TNode<JSArrayBuffer> tmp213;
    TNode<Object> tmp214;
    TNode<Object> tmp215;
    TNode<UintPtrT> tmp216;
    TNode<Int32T> tmp217;
    TNode<UintPtrT> tmp218;
    TNode<UintPtrT> tmp219;
    TNode<UintPtrT> tmp220;
    TNode<UintPtrT> tmp221;
    TNode<UintPtrT> tmp222;
    TNode<Int32T> tmp223;
    TNode<UintPtrT> tmp224;
    TNode<UintPtrT> tmp225;
    ca_.Bind(&block29, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225);
    ca_.Goto(&block5, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217);
  }

  if (block30.is_used()) {
    TNode<Context> tmp226;
    TNode<Map> tmp227;
    TNode<JSArrayBuffer> tmp228;
    TNode<Object> tmp229;
    TNode<Object> tmp230;
    TNode<UintPtrT> tmp231;
    TNode<Int32T> tmp232;
    TNode<UintPtrT> tmp233;
    TNode<UintPtrT> tmp234;
    TNode<UintPtrT> tmp235;
    TNode<UintPtrT> tmp236;
    TNode<UintPtrT> tmp237;
    TNode<Int32T> tmp238;
    TNode<UintPtrT> tmp239;
    TNode<UintPtrT> tmp240;
    ca_.Bind(&block30, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240);
    TNode<UintPtrT> tmp241;
    USE(tmp241);
    tmp241 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    TNode<UintPtrT> tmp242;
    USE(tmp242);
    tmp242 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp241}, TNode<UintPtrT>{tmp237});
    TNode<BoolT> tmp243;
    USE(tmp243);
    tmp243 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp240}, TNode<UintPtrT>{tmp242});
    ca_.Branch(tmp243, &block31, &block32, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp242);
  }

  if (block31.is_used()) {
    TNode<Context> tmp244;
    TNode<Map> tmp245;
    TNode<JSArrayBuffer> tmp246;
    TNode<Object> tmp247;
    TNode<Object> tmp248;
    TNode<UintPtrT> tmp249;
    TNode<Int32T> tmp250;
    TNode<UintPtrT> tmp251;
    TNode<UintPtrT> tmp252;
    TNode<UintPtrT> tmp253;
    TNode<UintPtrT> tmp254;
    TNode<UintPtrT> tmp255;
    TNode<Int32T> tmp256;
    TNode<UintPtrT> tmp257;
    TNode<UintPtrT> tmp258;
    TNode<UintPtrT> tmp259;
    ca_.Bind(&block31, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259);
    ca_.Goto(&block5, tmp244, tmp245, tmp246, tmp247, tmp248, tmp249, tmp250);
  }

  if (block32.is_used()) {
    TNode<Context> tmp260;
    TNode<Map> tmp261;
    TNode<JSArrayBuffer> tmp262;
    TNode<Object> tmp263;
    TNode<Object> tmp264;
    TNode<UintPtrT> tmp265;
    TNode<Int32T> tmp266;
    TNode<UintPtrT> tmp267;
    TNode<UintPtrT> tmp268;
    TNode<UintPtrT> tmp269;
    TNode<UintPtrT> tmp270;
    TNode<UintPtrT> tmp271;
    TNode<Int32T> tmp272;
    TNode<UintPtrT> tmp273;
    TNode<UintPtrT> tmp274;
    TNode<UintPtrT> tmp275;
    ca_.Bind(&block32, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275);
    TNode<UintPtrT> tmp276;
    USE(tmp276);
    tmp276 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp274}, TNode<UintPtrT>{tmp271});
    TNode<BoolT> tmp277;
    USE(tmp277);
    tmp277 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp270}, TNode<UintPtrT>{tmp276});
    ca_.Branch(tmp277, &block35, &block36, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp276, tmp270, tmp277);
  }

  if (block35.is_used()) {
    TNode<Context> tmp278;
    TNode<Map> tmp279;
    TNode<JSArrayBuffer> tmp280;
    TNode<Object> tmp281;
    TNode<Object> tmp282;
    TNode<UintPtrT> tmp283;
    TNode<Int32T> tmp284;
    TNode<UintPtrT> tmp285;
    TNode<UintPtrT> tmp286;
    TNode<UintPtrT> tmp287;
    TNode<UintPtrT> tmp288;
    TNode<BoolT> tmp289;
    ca_.Bind(&block35, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289);
    TNode<BoolT> tmp290;
    USE(tmp290);
    tmp290 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block37, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290);
  }

  if (block36.is_used()) {
    TNode<Context> tmp291;
    TNode<Map> tmp292;
    TNode<JSArrayBuffer> tmp293;
    TNode<Object> tmp294;
    TNode<Object> tmp295;
    TNode<UintPtrT> tmp296;
    TNode<Int32T> tmp297;
    TNode<UintPtrT> tmp298;
    TNode<UintPtrT> tmp299;
    TNode<UintPtrT> tmp300;
    TNode<UintPtrT> tmp301;
    TNode<BoolT> tmp302;
    ca_.Bind(&block36, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302);
    TNode<UintPtrT> tmp303;
    USE(tmp303);
    tmp303 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp301}, TNode<UintPtrT>{tmp300});
    TNode<BoolT> tmp304;
    USE(tmp304);
    tmp304 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp298}, TNode<UintPtrT>{tmp303});
    ca_.Goto(&block37, tmp291, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp304);
  }

  if (block37.is_used()) {
    TNode<Context> tmp305;
    TNode<Map> tmp306;
    TNode<JSArrayBuffer> tmp307;
    TNode<Object> tmp308;
    TNode<Object> tmp309;
    TNode<UintPtrT> tmp310;
    TNode<Int32T> tmp311;
    TNode<UintPtrT> tmp312;
    TNode<UintPtrT> tmp313;
    TNode<UintPtrT> tmp314;
    TNode<UintPtrT> tmp315;
    TNode<BoolT> tmp316;
    TNode<BoolT> tmp317;
    ca_.Bind(&block37, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317);
    ca_.Branch(tmp317, &block33, &block34, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315);
  }

  if (block33.is_used()) {
    TNode<Context> tmp318;
    TNode<Map> tmp319;
    TNode<JSArrayBuffer> tmp320;
    TNode<Object> tmp321;
    TNode<Object> tmp322;
    TNode<UintPtrT> tmp323;
    TNode<Int32T> tmp324;
    TNode<UintPtrT> tmp325;
    TNode<UintPtrT> tmp326;
    TNode<UintPtrT> tmp327;
    TNode<UintPtrT> tmp328;
    ca_.Bind(&block33, &tmp318, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328);
    ca_.Goto(&block5, tmp318, tmp319, tmp320, tmp321, tmp322, tmp323, tmp324);
  }

  if (block34.is_used()) {
    TNode<Context> tmp329;
    TNode<Map> tmp330;
    TNode<JSArrayBuffer> tmp331;
    TNode<Object> tmp332;
    TNode<Object> tmp333;
    TNode<UintPtrT> tmp334;
    TNode<Int32T> tmp335;
    TNode<UintPtrT> tmp336;
    TNode<UintPtrT> tmp337;
    TNode<UintPtrT> tmp338;
    TNode<UintPtrT> tmp339;
    ca_.Bind(&block34, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339);
    ca_.Goto(&block19, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336, tmp337, tmp338, tmp339);
  }

  if (block19.is_used()) {
    TNode<Context> tmp340;
    TNode<Map> tmp341;
    TNode<JSArrayBuffer> tmp342;
    TNode<Object> tmp343;
    TNode<Object> tmp344;
    TNode<UintPtrT> tmp345;
    TNode<Int32T> tmp346;
    TNode<UintPtrT> tmp347;
    TNode<UintPtrT> tmp348;
    TNode<UintPtrT> tmp349;
    TNode<UintPtrT> tmp350;
    ca_.Bind(&block19, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350);
    TNode<JSTypedArray> tmp351;
    USE(tmp351);
    tmp351 = AllocateTypedArray_0(state_, TNode<Context>{tmp340}, false, TNode<Map>{tmp341}, TNode<JSArrayBuffer>{tmp342}, TNode<UintPtrT>{tmp347}, TNode<UintPtrT>{tmp349}, TNode<UintPtrT>{tmp348});
    ca_.Goto(&block38, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp351);
  }

  if (block7.is_used()) {
    TNode<Context> tmp352;
    TNode<Map> tmp353;
    TNode<JSArrayBuffer> tmp354;
    TNode<Object> tmp355;
    TNode<Object> tmp356;
    TNode<UintPtrT> tmp357;
    TNode<Int32T> tmp358;
    TNode<String> tmp359;
    ca_.Bind(&block7, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidTypedArrayAlignment, tmp352, tmp353, tmp359);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp361;
    TNode<Map> tmp362;
    TNode<JSArrayBuffer> tmp363;
    TNode<Object> tmp364;
    TNode<Object> tmp365;
    TNode<UintPtrT> tmp366;
    TNode<Int32T> tmp367;
    ca_.Bind(&block5, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp361}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp365});
  }

  if (block3.is_used()) {
    TNode<Context> tmp368;
    TNode<Map> tmp369;
    TNode<JSArrayBuffer> tmp370;
    TNode<Object> tmp371;
    TNode<Object> tmp372;
    TNode<UintPtrT> tmp373;
    TNode<Int32T> tmp374;
    ca_.Bind(&block3, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp368}, MessageTemplate::kInvalidOffset, TNode<Object>{tmp371});
  }

    TNode<Context> tmp375;
    TNode<Map> tmp376;
    TNode<JSArrayBuffer> tmp377;
    TNode<Object> tmp378;
    TNode<Object> tmp379;
    TNode<UintPtrT> tmp380;
    TNode<Int32T> tmp381;
    TNode<JSTypedArray> tmp382;
    ca_.Bind(&block38, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382);
  return TNode<JSTypedArray>{tmp382};
}

TNode<JSTypedArray> TypedArrayCreateByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Number> p_length, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, JSTypedArray> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, JSTypedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, JSTypedArray> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, JSTypedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSTypedArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_constructor, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp0}, TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2});
    TNode<JSTypedArray> tmp4;
    USE(tmp4);
    tmp4 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArray(TNode<Context>{tmp0}, TNode<Object>{tmp3}, p_methodName);
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp5);
    TNode<JSArrayBuffer>tmp6 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp4, tmp5});
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp6});
    ca_.Branch(tmp7, &block6, &block7, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsSafeInteger(length)' failed", "src/builtins/typed-array-createtypedarray.tq", 292);
  }

  if (block4.is_used()) {
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Number> tmp13;
    ca_.Bind(&block4, &tmp11, &tmp12, &tmp13);
  }

  if (block6.is_used()) {
    TNode<Context> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Number> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<JSTypedArray> tmp18;
    ca_.Bind(&block6, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp14}, MessageTemplate::kDetachedOperation, p_methodName);
  }

  if (block7.is_used()) {
    TNode<Context> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Number> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<JSTypedArray> tmp23;
    ca_.Bind(&block7, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp24);
    TNode<UintPtrT>tmp25 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp23, tmp24});
    TNode<UintPtrT> tmp26;
    USE(tmp26);
    tmp26 = Convert_uintptr_Number_0(state_, TNode<Number>{tmp21});
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp26});
    ca_.Branch(tmp27, &block8, &block9, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block8.is_used()) {
    TNode<Context> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Number> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<JSTypedArray> tmp32;
    ca_.Bind(&block8, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp28}, MessageTemplate::kTypedArrayTooShort);
  }

  if (block9.is_used()) {
    TNode<Context> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Number> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<JSTypedArray> tmp37;
    ca_.Bind(&block9, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block10, tmp33, tmp34, tmp35, tmp37);
  }

    TNode<Context> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Number> tmp40;
    TNode<JSTypedArray> tmp41;
    ca_.Bind(&block10, &tmp38, &tmp39, &tmp40, &tmp41);
  return TNode<JSTypedArray>{tmp41};
}

void ConstructByJSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj, compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_0, compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Symbol, Context> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Symbol, Context, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Symbol, Context, JSReceiver> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, JSReceiver, JSReceiver, Context, JSArray, UintPtrT, JSReceiver> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, UintPtrT, JSReceiver> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_obj);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Symbol> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IteratorSymbolConstant();
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp3 = GetMethod_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Name>{tmp2}, &label0, &label1, &result_1_0);
    ca_.Goto(&block8, tmp0, tmp1, tmp1, tmp2, tmp0, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp0, tmp1, tmp1, tmp2, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block10, tmp0, tmp1, tmp1, tmp2, tmp0, result_1_0.value());
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp4;
    TNode<JSReceiver> tmp5;
    TNode<JSReceiver> tmp6;
    TNode<Symbol> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block9, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = kLengthString_0(state_);
    TNode<Object> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp4}, TNode<Object>{tmp5}, TNode<Object>{tmp9});
    TNode<Number> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp4}, TNode<Object>{tmp10});
    TNode<UintPtrT> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = ChangeSafeIntegerNumberToUintPtr_0(state_, TNode<Number>{tmp11}, &label0);
    ca_.Goto(&block14, tmp4, tmp5, tmp10, tmp11, tmp11, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp4, tmp5, tmp10, tmp11, tmp11);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Symbol> tmp16;
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    ca_.Bind(&block10, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp13}, MessageTemplate::kIteratorSymbolNonCallable);
  }

  if (block8.is_used()) {
    TNode<Context> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<Symbol> tmp22;
    TNode<Context> tmp23;
    TNode<JSReceiver> tmp24;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    compiler::TypedCodeAssemblerVariable<JSArray> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<JSReceiver> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    ConstructByIterable_0(state_, TNode<Context>{tmp19}, TNode<JSReceiver>{tmp20}, TNode<JSReceiver>{tmp24}, &label0, &result_0_0, &result_0_1, &result_0_2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp19, tmp20, tmp24, tmp20, tmp24, tmp19, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<JSReceiver> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Context> tmp30;
    TNode<JSArray> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<JSReceiver> tmp33;
    ca_.Bind(&block11, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block1, tmp31, tmp32, tmp33);
  }

  if (block15.is_used()) {
    TNode<Context> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<Object> tmp36;
    TNode<Number> tmp37;
    TNode<Number> tmp38;
    ca_.Bind(&block15, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp34}, MessageTemplate::kInvalidTypedArrayLength, TNode<Object>{tmp37});
  }

  if (block14.is_used()) {
    TNode<Context> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<Object> tmp41;
    TNode<Number> tmp42;
    TNode<Number> tmp43;
    TNode<UintPtrT> tmp44;
    ca_.Bind(&block14, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<JSReceiver> tmp45;
    USE(tmp45);
    tmp45 = GetArrayBufferFunction_0(state_, TNode<Context>{tmp39});
    ca_.Goto(&block1, tmp40, tmp44, tmp45);
  }

  if (block1.is_used()) {
    TNode<JSReceiver> tmp46;
    TNode<UintPtrT> tmp47;
    TNode<JSReceiver> tmp48;
    ca_.Bind(&block1, &tmp46, &tmp47, &tmp48);
    *label_IfConstructByArrayLike_parameter_2 = tmp48;
    *label_IfConstructByArrayLike_parameter_1 = tmp47;
    *label_IfConstructByArrayLike_parameter_0 = tmp46;
    ca_.Goto(label_IfConstructByArrayLike);
  }
}

TF_BUILTIN(CreateTypedArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSFunction> parameter1 = UncheckedCast<JSFunction>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<JSReceiver> parameter2 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<4>()));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, Object, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject, JSArrayBuffer> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject, JSTypedArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, JSTypedArray, JSTypedArray, Context, JSTypedArray, UintPtrT, JSReceiver> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, HeapObject, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object, JSReceiver, JSReceiver, Context, JSReceiver, UintPtrT, JSReceiver> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSFunction, JSReceiver, Object, Object, Object, Map, UintPtrT, Int32T, JSReceiver, UintPtrT, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = GetDerivedMap_0(state_, TNode<Context>{tmp0}, TNode<JSFunction>{tmp1}, TNode<JSReceiver>{tmp2});
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    TNode<Int32T> tmp8;
    USE(tmp8);
    std::tie(tmp7, tmp8) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map>{tmp6}).Flatten();
    TNode<Smi> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = Cast_Smi_0(state_, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block11, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp3, tmp3, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp3, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<JSFunction> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsConstructor(target)' failed", "src/builtins/typed-array-createtypedarray.tq", 351);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<JSFunction> tmp17;
    TNode<JSReceiver> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
  }

  if (block12.is_used()) {
    TNode<Context> tmp22;
    TNode<JSFunction> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Map> tmp28;
    TNode<UintPtrT> tmp29;
    TNode<Int32T> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    ca_.Bind(&block12, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<JSArrayBuffer> tmp33;
    USE(tmp33);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp33 = Cast_JSArrayBuffer_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp31)}, &label0);
    ca_.Goto(&block15, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, ca_.UncheckedCast<HeapObject>(tmp31), tmp33);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, ca_.UncheckedCast<HeapObject>(tmp31));
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp34;
    TNode<JSFunction> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<Map> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Int32T> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Smi> tmp45;
    ca_.Bind(&block11, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    ca_.Goto(&block8, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp45);
  }

  if (block16.is_used()) {
    TNode<Context> tmp46;
    TNode<JSFunction> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Map> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<Int32T> tmp54;
    TNode<Object> tmp55;
    TNode<HeapObject> tmp56;
    ca_.Bind(&block16, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<JSTypedArray> tmp57;
    USE(tmp57);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp57 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp55)}, &label0);
    ca_.Goto(&block19, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, ca_.UncheckedCast<HeapObject>(tmp55), tmp57);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, ca_.UncheckedCast<HeapObject>(tmp55));
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp58;
    TNode<JSFunction> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<Object> tmp63;
    TNode<Map> tmp64;
    TNode<UintPtrT> tmp65;
    TNode<Int32T> tmp66;
    TNode<Object> tmp67;
    TNode<HeapObject> tmp68;
    TNode<JSArrayBuffer> tmp69;
    ca_.Bind(&block15, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<JSTypedArray> tmp70;
    USE(tmp70);
    tmp70 = ConstructByArrayBuffer_0(state_, TNode<Context>{tmp58}, TNode<Map>{tmp64}, TNode<JSArrayBuffer>{tmp69}, TNode<Object>{tmp62}, TNode<Object>{tmp63}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp65}, TNode<Int32T>{tmp66}});
    CodeStubAssembler(state_).Return(tmp70);
  }

  if (block20.is_used()) {
    TNode<Context> tmp71;
    TNode<JSFunction> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<Map> tmp77;
    TNode<UintPtrT> tmp78;
    TNode<Int32T> tmp79;
    TNode<Object> tmp80;
    TNode<HeapObject> tmp81;
    ca_.Bind(&block20, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<JSReceiver> tmp82;
    USE(tmp82);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp82 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp80)}, &label0);
    ca_.Goto(&block24, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, ca_.UncheckedCast<HeapObject>(tmp80), tmp82);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, ca_.UncheckedCast<HeapObject>(tmp80));
    }
  }

  if (block19.is_used()) {
    TNode<Context> tmp83;
    TNode<JSFunction> tmp84;
    TNode<JSReceiver> tmp85;
    TNode<Object> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<Map> tmp89;
    TNode<UintPtrT> tmp90;
    TNode<Int32T> tmp91;
    TNode<Object> tmp92;
    TNode<HeapObject> tmp93;
    TNode<JSTypedArray> tmp94;
    ca_.Bind(&block19, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    compiler::TypedCodeAssemblerVariable<JSTypedArray> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<JSReceiver> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    ConstructByTypedArray_0(state_, TNode<Context>{tmp83}, TNode<JSTypedArray>{tmp94}, &label0, &result_0_0, &result_0_1, &result_0_2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp94, tmp94, tmp83, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
  }

  if (block21.is_used()) {
    TNode<Context> tmp95;
    TNode<JSFunction> tmp96;
    TNode<JSReceiver> tmp97;
    TNode<Object> tmp98;
    TNode<Object> tmp99;
    TNode<Object> tmp100;
    TNode<Map> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<Int32T> tmp103;
    TNode<Object> tmp104;
    TNode<JSTypedArray> tmp105;
    TNode<JSTypedArray> tmp106;
    TNode<Context> tmp107;
    TNode<JSTypedArray> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<JSReceiver> tmp110;
    ca_.Bind(&block21, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    ca_.Goto(&block6, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp108, tmp109, tmp110);
  }

  if (block25.is_used()) {
    TNode<Context> tmp111;
    TNode<JSFunction> tmp112;
    TNode<JSReceiver> tmp113;
    TNode<Object> tmp114;
    TNode<Object> tmp115;
    TNode<Object> tmp116;
    TNode<Map> tmp117;
    TNode<UintPtrT> tmp118;
    TNode<Int32T> tmp119;
    TNode<Object> tmp120;
    TNode<HeapObject> tmp121;
    ca_.Bind(&block25, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    ca_.Goto(&block8, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, ca_.UncheckedCast<PrimitiveHeapObject>(tmp120));
  }

  if (block24.is_used()) {
    TNode<Context> tmp122;
    TNode<JSFunction> tmp123;
    TNode<JSReceiver> tmp124;
    TNode<Object> tmp125;
    TNode<Object> tmp126;
    TNode<Object> tmp127;
    TNode<Map> tmp128;
    TNode<UintPtrT> tmp129;
    TNode<Int32T> tmp130;
    TNode<Object> tmp131;
    TNode<HeapObject> tmp132;
    TNode<JSReceiver> tmp133;
    ca_.Bind(&block24, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    compiler::TypedCodeAssemblerVariable<JSReceiver> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> result_0_1(&ca_);
    compiler::TypedCodeAssemblerVariable<JSReceiver> result_0_2(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    ConstructByJSReceiver_0(state_, TNode<Context>{tmp122}, TNode<JSReceiver>{tmp133}, &label0, &result_0_0, &result_0_1, &result_0_2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block26, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp133, tmp133, tmp122, result_0_0.value(), result_0_1.value(), result_0_2.value());
    }
  }

  if (block26.is_used()) {
    TNode<Context> tmp134;
    TNode<JSFunction> tmp135;
    TNode<JSReceiver> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    TNode<Object> tmp139;
    TNode<Map> tmp140;
    TNode<UintPtrT> tmp141;
    TNode<Int32T> tmp142;
    TNode<Object> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<JSReceiver> tmp145;
    TNode<Context> tmp146;
    TNode<JSReceiver> tmp147;
    TNode<UintPtrT> tmp148;
    TNode<JSReceiver> tmp149;
    ca_.Bind(&block26, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    ca_.Goto(&block6, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp147, tmp148, tmp149);
  }

  if (block8.is_used()) {
    TNode<Context> tmp150;
    TNode<JSFunction> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<Map> tmp156;
    TNode<UintPtrT> tmp157;
    TNode<Int32T> tmp158;
    TNode<Object> tmp159;
    ca_.Bind(&block8, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159);
    TNode<JSTypedArray> tmp160;
    USE(tmp160);
    tmp160 = ConstructByLength_0(state_, TNode<Context>{tmp150}, TNode<Map>{tmp156}, TNode<Object>{tmp159}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp157}, TNode<Int32T>{tmp158}});
    CodeStubAssembler(state_).Return(tmp160);
  }

  if (block6.is_used()) {
    TNode<Context> tmp161;
    TNode<JSFunction> tmp162;
    TNode<JSReceiver> tmp163;
    TNode<Object> tmp164;
    TNode<Object> tmp165;
    TNode<Object> tmp166;
    TNode<Map> tmp167;
    TNode<UintPtrT> tmp168;
    TNode<Int32T> tmp169;
    TNode<JSReceiver> tmp170;
    TNode<UintPtrT> tmp171;
    TNode<JSReceiver> tmp172;
    ca_.Bind(&block6, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172);
    TNode<JSTypedArray> tmp173;
    USE(tmp173);
    tmp173 = ConstructByArrayLike_0(state_, TNode<Context>{tmp161}, TNode<Map>{tmp167}, TNode<HeapObject>{tmp170}, TNode<UintPtrT>{tmp171}, TorqueStructTypedArrayElementsInfo{TNode<UintPtrT>{tmp168}, TNode<Int32T>{tmp169}}, TNode<JSReceiver>{tmp172});
    CodeStubAssembler(state_).Return(tmp173);
  }
}

TNode<JSTypedArray> TypedArraySpeciesCreate_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, int31_t p_numArgs, TNode<JSTypedArray> p_exemplar, TNode<Object> p_arg0, TNode<Object> p_arg1, TNode<Object> p_arg2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSTypedArray> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSTypedArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, JSReceiver> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, Object> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSFunction, JSReceiver, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSTypedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, Object, Object, Object, JSTypedArray> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_exemplar, p_arg0, p_arg1, p_arg2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSFunction> tmp5;
    USE(tmp5);
    tmp5 = TypedArrayBuiltinsAssembler(state_).GetDefaultConstructor(TNode<Context>{tmp0}, TNode<JSTypedArray>{tmp1});
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp6);
    TNode<Map>tmp7 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp6});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).IsPrototypeTypedArrayPrototype(TNode<Context>{tmp0}, TNode<Map>{tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp8});
    ca_.Branch(tmp9, &block4, &block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<JSTypedArray> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<JSFunction> tmp15;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    ca_.Goto(&block3, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block5.is_used()) {
    TNode<Context> tmp16;
    TNode<JSTypedArray> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<JSFunction> tmp21;
    ca_.Bind(&block5, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).IsTypedArraySpeciesProtectorCellInvalid();
    ca_.Branch(tmp22, &block6, &block7, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block6.is_used()) {
    TNode<Context> tmp23;
    TNode<JSTypedArray> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<JSFunction> tmp28;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block3, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<JSTypedArray> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<JSFunction> tmp34;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<JSTypedArray> tmp35;
    tmp35 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateTypedArray, tmp29, tmp34, tmp34, tmp31, tmp32, tmp33));
    USE(tmp35);
    ca_.Goto(&block1, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block11.is_used()) {
    TNode<Context> tmp36;
    TNode<JSTypedArray> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<JSFunction> tmp41;
    TNode<JSTypedArray> tmp42;
    ca_.Bind(&block11, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsDetachedBuffer(typedArray.buffer)' failed", "src/builtins/typed-array-createtypedarray.tq", 406);
  }

  if (block10.is_used()) {
    TNode<Context> tmp43;
    TNode<JSTypedArray> tmp44;
    TNode<Object> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<JSFunction> tmp48;
    TNode<JSTypedArray> tmp49;
    ca_.Bind(&block10, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
  }

  if (block3.is_used()) {
    TNode<Context> tmp50;
    TNode<JSTypedArray> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<Object> tmp54;
    TNode<JSFunction> tmp55;
    ca_.Bind(&block3, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<JSReceiver> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{tmp50}, TNode<Object>{tmp51}, TNode<JSReceiver>{tmp55});
    TNode<JSReceiver> tmp57;
    USE(tmp57);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp57 = Cast_Constructor_0(state_, TNode<HeapObject>{tmp56}, &label0);
    ca_.Goto(&block14, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56);
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp58;
    TNode<JSTypedArray> tmp59;
    TNode<Object> tmp60;
    TNode<Object> tmp61;
    TNode<Object> tmp62;
    TNode<JSFunction> tmp63;
    TNode<JSReceiver> tmp64;
    ca_.Bind(&block15, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block14.is_used()) {
    TNode<Context> tmp65;
    TNode<JSTypedArray> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<JSFunction> tmp70;
    TNode<JSReceiver> tmp71;
    TNode<JSReceiver> tmp72;
    ca_.Bind(&block14, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<Oddball> tmp73;
    USE(tmp73);
    tmp73 = Undefined_0(state_);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_numArgs, 1)))) {
      ca_.Goto(&block16, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72, tmp73);
    } else {
      ca_.Goto(&block17, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72, tmp73);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp74;
    TNode<JSTypedArray> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<JSFunction> tmp79;
    TNode<JSReceiver> tmp80;
    TNode<Object> tmp81;
    ca_.Bind(&block16, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<JSReceiver> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp74}, TNode<JSReceiver>{tmp80}, TNode<Object>{tmp76});
    ca_.Goto(&block18, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp82);
  }

  if (block17.is_used()) {
    TNode<Context> tmp83;
    TNode<JSTypedArray> tmp84;
    TNode<Object> tmp85;
    TNode<Object> tmp86;
    TNode<Object> tmp87;
    TNode<JSFunction> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block17, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<JSReceiver> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp83}, TNode<JSReceiver>{tmp89}, TNode<Object>{tmp85}, TNode<Object>{tmp86}, TNode<Object>{tmp87});
    ca_.Goto(&block18, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp91);
  }

  if (block22.is_used()) {
    TNode<Context> tmp92;
    TNode<JSTypedArray> tmp93;
    TNode<Object> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<JSFunction> tmp97;
    TNode<JSReceiver> tmp98;
    TNode<Object> tmp99;
    ca_.Bind(&block22, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    CodeStubAssembler(state_).FailAssert("Torque assert 'numArgs == 3' failed", "src/builtins/typed-array-createtypedarray.tq", 421);
  }

  if (block21.is_used()) {
    TNode<Context> tmp100;
    TNode<JSTypedArray> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<JSFunction> tmp105;
    TNode<JSReceiver> tmp106;
    TNode<Object> tmp107;
    ca_.Bind(&block21, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
  }

  if (block18.is_used()) {
    TNode<Context> tmp108;
    TNode<JSTypedArray> tmp109;
    TNode<Object> tmp110;
    TNode<Object> tmp111;
    TNode<Object> tmp112;
    TNode<JSFunction> tmp113;
    TNode<JSReceiver> tmp114;
    TNode<Object> tmp115;
    ca_.Bind(&block18, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115);
    TNode<JSTypedArray> tmp116;
    USE(tmp116);
    tmp116 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArray(TNode<Context>{tmp108}, TNode<Object>{tmp115}, p_methodName);
    ca_.Goto(&block1, tmp108, tmp109, tmp110, tmp111, tmp112, tmp116);
  }

  if (block1.is_used()) {
    TNode<Context> tmp117;
    TNode<JSTypedArray> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<Object> tmp121;
    TNode<JSTypedArray> tmp122;
    ca_.Bind(&block1, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    ca_.Goto(&block23, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122);
  }

    TNode<Context> tmp123;
    TNode<JSTypedArray> tmp124;
    TNode<Object> tmp125;
    TNode<Object> tmp126;
    TNode<Object> tmp127;
    TNode<JSTypedArray> tmp128;
    ca_.Bind(&block23, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
  return TNode<JSTypedArray>{tmp128};
}

TNode<JSTypedArray> TypedArraySpeciesCreateByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, TNode<JSTypedArray> p_exemplar, TNode<UintPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, JSTypedArray> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, JSTypedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, UintPtrT, JSTypedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_exemplar, p_length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<UintPtrT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp2});
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = Undefined_0(state_);
    TNode<JSTypedArray> tmp6;
    USE(tmp6);
    tmp6 = TypedArraySpeciesCreate_0(state_, TNode<Context>{tmp0}, p_methodName, 1, TNode<JSTypedArray>{tmp1}, TNode<Object>{tmp3}, TNode<Object>{tmp4}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp7);
    TNode<UintPtrT>tmp8 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp2});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp6);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<JSTypedArray> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<JSTypedArray> tmp13;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp10}, MessageTemplate::kTypedArrayTooShort);
  }

  if (block3.is_used()) {
    TNode<Context> tmp14;
    TNode<JSTypedArray> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<JSTypedArray> tmp17;
    ca_.Bind(&block3, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block4, tmp14, tmp15, tmp16, tmp17);
  }

    TNode<Context> tmp18;
    TNode<JSTypedArray> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<JSTypedArray> tmp21;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21);
  return TNode<JSTypedArray>{tmp21};
}

TNode<JSTypedArray> TypedArraySpeciesCreateByBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, TNode<JSTypedArray> p_exemplar, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_beginByteOffset, TNode<UintPtrT> p_newLength) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSArrayBuffer, UintPtrT, UintPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSArrayBuffer, UintPtrT, UintPtrT, JSTypedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_exemplar, p_buffer, p_beginByteOffset, p_newLength);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<JSArrayBuffer> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp3});
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp4});
    TNode<JSTypedArray> tmp7;
    USE(tmp7);
    tmp7 = TypedArraySpeciesCreate_0(state_, TNode<Context>{tmp0}, p_methodName, 3, TNode<JSTypedArray>{tmp1}, TNode<Object>{tmp2}, TNode<Object>{tmp5}, TNode<Object>{tmp6});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp7);
  }

    TNode<Context> tmp8;
    TNode<JSTypedArray> tmp9;
    TNode<JSArrayBuffer> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<JSTypedArray> tmp13;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
  return TNode<JSTypedArray>{tmp13};
}

TNode<JSArrayBuffer> Cast_JSArrayBuffer_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSArrayBuffer> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArrayBuffer> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSArrayBuffer> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSArrayBuffer_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSArrayBuffer> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSArrayBuffer> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSArrayBuffer>{tmp20};
}

}  // namespace internal
}  // namespace v8

