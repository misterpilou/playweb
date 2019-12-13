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

TF_BUILTIN(TypedArrayPrototypeSubArray, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext, JSTypedArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT, UintPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSArrayBuffer, UintPtrT, Object, UintPtrT, Object, UintPtrT, UintPtrT, UintPtrT, Int32T, UintPtrT, UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSTypedArray_1(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<NativeContext> tmp12;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp9}, MessageTemplate::kIncompatibleMethodReceiver, "%TypedArray%.prototype.subarray");
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    TNode<JSTypedArray> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<JSArrayBuffer> tmp21;
    USE(tmp21);
    tmp21 = TypedArrayBuiltinsAssembler(state_).GetBuffer(TNode<Context>{tmp16}, TNode<JSTypedArray>{tmp20});
    TNode<IntPtrT> tmp22 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp22);
    TNode<UintPtrT>tmp23 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp20, tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp13}, TNode<RawPtrT>{tmp14}, TNode<IntPtrT>{tmp15}}, TNode<IntPtrT>{tmp24});
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = Undefined_0(state_);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp25}, TNode<HeapObject>{tmp26});
    ca_.Branch(tmp27, &block5, &block6, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp21, tmp23, tmp25);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<JSTypedArray> tmp33;
    TNode<JSArrayBuffer> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<Object> tmp36;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<UintPtrT> tmp37;
    USE(tmp37);
    tmp37 = ConvertToRelativeIndex_1(state_, TNode<Context>{tmp31}, TNode<Object>{tmp36}, TNode<UintPtrT>{tmp35});
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp38;
    TNode<RawPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<JSTypedArray> tmp43;
    TNode<JSArrayBuffer> tmp44;
    TNode<UintPtrT> tmp45;
    TNode<Object> tmp46;
    ca_.Bind(&block6, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<UintPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block7, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp48;
    TNode<RawPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<JSTypedArray> tmp53;
    TNode<JSArrayBuffer> tmp54;
    TNode<UintPtrT> tmp55;
    TNode<Object> tmp56;
    TNode<UintPtrT> tmp57;
    ca_.Bind(&block7, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<IntPtrT> tmp58;
    USE(tmp58);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp48}, TNode<RawPtrT>{tmp49}, TNode<IntPtrT>{tmp50}}, TNode<IntPtrT>{tmp58});
    TNode<Oddball> tmp60;
    USE(tmp60);
    tmp60 = Undefined_0(state_);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp59}, TNode<HeapObject>{tmp60});
    ca_.Branch(tmp61, &block9, &block10, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp59);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp62;
    TNode<RawPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<JSTypedArray> tmp67;
    TNode<JSArrayBuffer> tmp68;
    TNode<UintPtrT> tmp69;
    TNode<Object> tmp70;
    TNode<UintPtrT> tmp71;
    TNode<Object> tmp72;
    ca_.Bind(&block9, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<UintPtrT> tmp73;
    USE(tmp73);
    tmp73 = ConvertToRelativeIndex_1(state_, TNode<Context>{tmp65}, TNode<Object>{tmp72}, TNode<UintPtrT>{tmp69});
    ca_.Goto(&block11, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp74;
    TNode<RawPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<NativeContext> tmp77;
    TNode<Object> tmp78;
    TNode<JSTypedArray> tmp79;
    TNode<JSArrayBuffer> tmp80;
    TNode<UintPtrT> tmp81;
    TNode<Object> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<Object> tmp84;
    ca_.Bind(&block10, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    ca_.Goto(&block11, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp81);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp85;
    TNode<RawPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<NativeContext> tmp88;
    TNode<Object> tmp89;
    TNode<JSTypedArray> tmp90;
    TNode<JSArrayBuffer> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<Object> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<Object> tmp95;
    TNode<UintPtrT> tmp96;
    ca_.Bind(&block11, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96);
    TNode<UintPtrT> tmp97;
    USE(tmp97);
    tmp97 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp96}, TNode<UintPtrT>{tmp94});
    TNode<IntPtrT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp97});
    TNode<IntPtrT> tmp99;
    USE(tmp99);
    tmp99 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).IntPtrMax(TNode<IntPtrT>{tmp98}, TNode<IntPtrT>{tmp99});
    TNode<UintPtrT> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp100});
    TNode<UintPtrT> tmp102;
    USE(tmp102);
    TNode<Int32T> tmp103;
    USE(tmp103);
    std::tie(tmp102, tmp103) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{tmp90}).Flatten();
    TNode<IntPtrT> tmp104 = ca_.IntPtrConstant(JSArrayBufferView::kByteOffsetOffset);
    USE(tmp104);
    TNode<UintPtrT>tmp105 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp90, tmp104});
    TNode<UintPtrT> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSTypedArray::kMaxLength);
    TNode<BoolT> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp94}, TNode<UintPtrT>{tmp106});
    ca_.Branch(tmp107, &block16, &block17, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp101, tmp102, tmp103, tmp105, tmp105, tmp102, tmp103, tmp94, tmp94);
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp108;
    TNode<RawPtrT> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<NativeContext> tmp111;
    TNode<Object> tmp112;
    TNode<JSTypedArray> tmp113;
    TNode<JSArrayBuffer> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<Object> tmp116;
    TNode<UintPtrT> tmp117;
    TNode<Object> tmp118;
    TNode<UintPtrT> tmp119;
    TNode<UintPtrT> tmp120;
    TNode<UintPtrT> tmp121;
    TNode<Int32T> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<UintPtrT> tmp124;
    TNode<UintPtrT> tmp125;
    TNode<Int32T> tmp126;
    TNode<UintPtrT> tmp127;
    TNode<UintPtrT> tmp128;
    ca_.Bind(&block16, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128);
    ca_.Goto(&block14, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp129;
    TNode<RawPtrT> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<NativeContext> tmp132;
    TNode<Object> tmp133;
    TNode<JSTypedArray> tmp134;
    TNode<JSArrayBuffer> tmp135;
    TNode<UintPtrT> tmp136;
    TNode<Object> tmp137;
    TNode<UintPtrT> tmp138;
    TNode<Object> tmp139;
    TNode<UintPtrT> tmp140;
    TNode<UintPtrT> tmp141;
    TNode<UintPtrT> tmp142;
    TNode<Int32T> tmp143;
    TNode<UintPtrT> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<UintPtrT> tmp146;
    TNode<Int32T> tmp147;
    TNode<UintPtrT> tmp148;
    TNode<UintPtrT> tmp149;
    ca_.Bind(&block17, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    TNode<UintPtrT> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    TNode<UintPtrT> tmp151;
    USE(tmp151);
    tmp151 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp150}, TNode<UintPtrT>{tmp146});
    TNode<BoolT> tmp152;
    USE(tmp152);
    tmp152 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp149}, TNode<UintPtrT>{tmp151});
    ca_.Branch(tmp152, &block18, &block19, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp151);
  }

  if (block18.is_used()) {
    TNode<RawPtrT> tmp153;
    TNode<RawPtrT> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<NativeContext> tmp156;
    TNode<Object> tmp157;
    TNode<JSTypedArray> tmp158;
    TNode<JSArrayBuffer> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<Object> tmp161;
    TNode<UintPtrT> tmp162;
    TNode<Object> tmp163;
    TNode<UintPtrT> tmp164;
    TNode<UintPtrT> tmp165;
    TNode<UintPtrT> tmp166;
    TNode<Int32T> tmp167;
    TNode<UintPtrT> tmp168;
    TNode<UintPtrT> tmp169;
    TNode<UintPtrT> tmp170;
    TNode<Int32T> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<UintPtrT> tmp174;
    ca_.Bind(&block18, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    ca_.Goto(&block14, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169);
  }

  if (block19.is_used()) {
    TNode<RawPtrT> tmp175;
    TNode<RawPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<NativeContext> tmp178;
    TNode<Object> tmp179;
    TNode<JSTypedArray> tmp180;
    TNode<JSArrayBuffer> tmp181;
    TNode<UintPtrT> tmp182;
    TNode<Object> tmp183;
    TNode<UintPtrT> tmp184;
    TNode<Object> tmp185;
    TNode<UintPtrT> tmp186;
    TNode<UintPtrT> tmp187;
    TNode<UintPtrT> tmp188;
    TNode<Int32T> tmp189;
    TNode<UintPtrT> tmp190;
    TNode<UintPtrT> tmp191;
    TNode<UintPtrT> tmp192;
    TNode<Int32T> tmp193;
    TNode<UintPtrT> tmp194;
    TNode<UintPtrT> tmp195;
    TNode<UintPtrT> tmp196;
    ca_.Bind(&block19, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196);
    TNode<UintPtrT> tmp197;
    USE(tmp197);
    tmp197 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp195}, TNode<UintPtrT>{tmp192});
    TNode<UintPtrT> tmp198;
    USE(tmp198);
    tmp198 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp191}, TNode<UintPtrT>{tmp197});
    TNode<JSTypedArray> tmp199;
    USE(tmp199);
    tmp199 = TypedArraySpeciesCreateByBuffer_0(state_, TNode<Context>{tmp178}, "%TypedArray%.prototype.subarray", TNode<JSTypedArray>{tmp180}, TNode<JSArrayBuffer>{tmp181}, TNode<UintPtrT>{tmp198}, TNode<UintPtrT>{tmp187});
    arguments.PopAndReturn(tmp199);
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp200;
    TNode<RawPtrT> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<NativeContext> tmp203;
    TNode<Object> tmp204;
    TNode<JSTypedArray> tmp205;
    TNode<JSArrayBuffer> tmp206;
    TNode<UintPtrT> tmp207;
    TNode<Object> tmp208;
    TNode<UintPtrT> tmp209;
    TNode<Object> tmp210;
    TNode<UintPtrT> tmp211;
    TNode<UintPtrT> tmp212;
    TNode<UintPtrT> tmp213;
    TNode<Int32T> tmp214;
    TNode<UintPtrT> tmp215;
    TNode<UintPtrT> tmp216;
    ca_.Bind(&block14, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp203}, MessageTemplate::kInvalidArrayBufferLength);
  }
}

}  // namespace internal
}  // namespace v8

