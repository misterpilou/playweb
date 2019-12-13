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

void ReduceToSmiOrFloat64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x, compiler::CodeAssemblerLabel* label_SmiResult, compiler::TypedCodeAssemblerVariable<Smi>* label_SmiResult_parameter_0, compiler::CodeAssemblerLabel* label_Float64Result, compiler::TypedCodeAssemblerVariable<Float64T>* label_Float64Result_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Object, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, HeapObject, HeapNumber> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block5, tmp0, tmp1, tmp1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp5, &block3, &block4, tmp2, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    TNode<Smi> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = Cast_Smi_0(state_, TNode<Object>{tmp8}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp8, tmp8, tmp8, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp8, tmp8, tmp8);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<HeapNumber> tmp15;
    USE(tmp15);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp15 = Cast_HeapNumber_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp13)}, &label0);
    ca_.Goto(&block12, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13), tmp15);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp10, tmp11, tmp12, tmp13, ca_.UncheckedCast<HeapObject>(tmp13));
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block8, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    *label_SmiResult_parameter_0 = tmp21;
    ca_.Goto(label_SmiResult);
  }

  if (block13.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<HeapObject> tmp26;
    ca_.Bind(&block13, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<Number> tmp27;
    tmp27 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNonNumberToNumber, tmp22, ca_.UncheckedCast<HeapObject>(tmp25)));
    USE(tmp27);
    ca_.Goto(&block5, tmp22, tmp23, tmp27);
  }

  if (block12.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp31;
    TNode<HeapObject> tmp32;
    TNode<HeapNumber> tmp33;
    ca_.Bind(&block12, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Float64T> tmp34;
    USE(tmp34);
    tmp34 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber>{tmp33});
    *label_Float64Result_parameter_0 = tmp34;
    ca_.Goto(label_Float64Result);
  }

  if (block4.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    ca_.Bind(&block4, &tmp35, &tmp36, &tmp37);
    VerifiedUnreachable_0(state_);
  }
}

TF_BUILTIN(MathAbs, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &result_0_0, &label1, &result_1_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0, result_0_0.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0, result_1_0.value());
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    if (((CodeStubAssembler(state_).IsIntPtrAbsWithOverflowSupported()))) {
      ca_.Goto(&block9, tmp2, tmp3, tmp6);
    } else {
      ca_.Goto(&block10, tmp2, tmp3, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Float64T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block9, &tmp14, &tmp15, &tmp16);
    TNode<Smi> tmp17;
    USE(tmp17);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp17 = CodeStubAssembler(state_).TrySmiAbs(TNode<Smi>{tmp16}, &label0);
    ca_.Goto(&block12, tmp14, tmp15, tmp16, tmp16, tmp17);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp14, tmp15, tmp16, tmp16);
    }
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block13, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block8, tmp18, tmp19, tmp20);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp22;
    TNode<Object> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    TNode<Smi> tmp26;
    ca_.Bind(&block12, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    CodeStubAssembler(state_).Return(tmp26);
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp27;
    TNode<Object> tmp28;
    TNode<Smi> tmp29;
    ca_.Bind(&block10, &tmp27, &tmp28, &tmp29);
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp29});
    ca_.Branch(tmp31, &block14, &block15, tmp27, tmp28, tmp29);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<Smi> tmp34;
    ca_.Bind(&block14, &tmp32, &tmp33, &tmp34);
    CodeStubAssembler(state_).Return(tmp34);
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<Smi> tmp37;
    ca_.Bind(&block15, &tmp35, &tmp36, &tmp37);
    TNode<Smi> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp39;
    USE(tmp39);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp39 = CodeStubAssembler(state_).TrySmiSub(TNode<Smi>{tmp38}, TNode<Smi>{tmp37}, &label0);
    ca_.Goto(&block17, tmp35, tmp36, tmp37, tmp37, tmp39);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block18, tmp35, tmp36, tmp37, tmp37);
    }
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    ca_.Bind(&block18, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block8, tmp40, tmp41, tmp42);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp44;
    TNode<Object> tmp45;
    TNode<Smi> tmp46;
    TNode<Smi> tmp47;
    TNode<Smi> tmp48;
    ca_.Bind(&block17, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    CodeStubAssembler(state_).Return(tmp48);
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp49;
    TNode<Object> tmp50;
    TNode<Smi> tmp51;
    ca_.Bind(&block8, &tmp49, &tmp50, &tmp51);
    TNode<Number> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).NumberConstant(0.0 - kSmiMinValue);
    CodeStubAssembler(state_).Return(tmp52);
  }
}

TF_BUILTIN(MathCeil, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &result_0_0, &label1, &result_1_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0, result_0_0.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0, result_1_0.value());
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Float64T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Float64Ceil(TNode<Float64T>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(MathFloor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &result_0_0, &label1, &result_1_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0, result_0_0.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0, result_1_0.value());
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Float64T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Float64Floor(TNode<Float64T>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(MathRound, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &result_0_0, &label1, &result_1_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0, result_0_0.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0, result_1_0.value());
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Float64T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Float64Round(TNode<Float64T>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TF_BUILTIN(MathTrunc, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, Float64T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> result_1_0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    ReduceToSmiOrFloat64_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &result_0_0, &label1, &result_1_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0, result_0_0.value());
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0, result_1_0.value());
    }
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Float64T> tmp11;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Float64T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Float64Trunc(TNode<Float64T>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TNode<Number> MathPowImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_base, TNode<Object> p_exponent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_base, p_exponent);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<Float64T> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Float64Pow(TNode<Float64T>{tmp3}, TNode<Float64T>{tmp4});
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp5});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10);
  return TNode<Number>{tmp10};
}

TF_BUILTIN(MathPow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kBase));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kExponent));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = MathPowImpl_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(MathMax, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_float64_constexpr_float64_0(state_, -V8_INFINITY);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp2, tmp5);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Float64T> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp13, &block1, &block2, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Float64T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Object> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp14}, TNode<RawPtrT>{tmp15}, TNode<IntPtrT>{tmp16}}, TNode<IntPtrT>{tmp20});
    TNode<Float64T> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{tmp17}, TNode<Object>{tmp21});
    TNode<Float64T> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).Float64Max(TNode<Float64T>{tmp18}, TNode<Float64T>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp24});
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp23, tmp19, tmp25);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp26;
    TNode<RawPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<NativeContext> tmp29;
    TNode<Float64T> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    ca_.Bind(&block2, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<Number> tmp33;
    USE(tmp33);
    tmp33 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp30});
    arguments.PopAndReturn(tmp33);
  }
}

TF_BUILTIN(MathMin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Float64T, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp2, tmp5);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Float64T> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp13, &block1, &block2, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Float64T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Object> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp14}, TNode<RawPtrT>{tmp15}, TNode<IntPtrT>{tmp16}}, TNode<IntPtrT>{tmp20});
    TNode<Float64T> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context>{tmp17}, TNode<Object>{tmp21});
    TNode<Float64T> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).Float64Min(TNode<Float64T>{tmp18}, TNode<Float64T>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp24});
    ca_.Goto(&block3, tmp14, tmp15, tmp16, tmp17, tmp23, tmp19, tmp25);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp26;
    TNode<RawPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<NativeContext> tmp29;
    TNode<Float64T> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    ca_.Bind(&block2, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    TNode<Number> tmp33;
    USE(tmp33);
    tmp33 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp30});
    arguments.PopAndReturn(tmp33);
  }
}

TF_BUILTIN(MathAcos, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Acos(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAcosh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Acosh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAsin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Asin(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAsinh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Asinh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAtan, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Atan(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathAtan2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kY));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = Convert_float64_Number_0(state_, TNode<Number>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<Float64T> tmp6;
    USE(tmp6);
    tmp6 = Convert_float64_Number_0(state_, TNode<Number>{tmp5});
    TNode<Float64T> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Float64Atan2(TNode<Float64T>{tmp4}, TNode<Float64T>{tmp6});
    TNode<Number> tmp8;
    USE(tmp8);
    tmp8 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp7});
    CodeStubAssembler(state_).Return(tmp8);
  }
}

TF_BUILTIN(MathAtanh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Atanh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathCbrt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Cbrt(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathClz32, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = Convert_int32_Number_0(state_, TNode<Number>{tmp2});
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Word32Clz(TNode<Int32T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_int32_0(state_, TNode<Int32T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathCos, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Cos(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathCosh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Cosh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathExp, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Exp(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathExpm1, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Expm1(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathFround, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float32T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float32_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = Convert_float64_float32_0(state_, TNode<Float32T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathImul, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kY));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = Convert_int32_Number_0(state_, TNode<Number>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = Convert_int32_Number_0(state_, TNode<Number>{tmp5});
    TNode<Int32T> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{tmp4}, TNode<Int32T>{tmp6});
    TNode<Number> tmp8;
    USE(tmp8);
    tmp8 = Convert_Number_int32_0(state_, TNode<Int32T>{tmp7});
    CodeStubAssembler(state_).Return(tmp8);
  }
}

TF_BUILTIN(MathLog, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Log(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathLog1p, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Log1p(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathLog10, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Log10(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathLog2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Log2(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathSin, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Sin(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathSign, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Float64T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Number, Float64T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp3}, TNode<Float64T>{tmp4});
    ca_.Branch(tmp5, &block1, &block2, tmp0, tmp1, tmp2, tmp3);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp6;
    TNode<Object> tmp7;
    TNode<Number> tmp8;
    TNode<Float64T> tmp9;
    ca_.Bind(&block1, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<Number> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Number_constexpr_int31_0(state_, -1);
    CodeStubAssembler(state_).Return(tmp10);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Number> tmp13;
    TNode<Float64T> tmp14;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Float64T> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp14}, TNode<Float64T>{tmp15});
    ca_.Branch(tmp16, &block4, &block5, tmp11, tmp12, tmp13, tmp14);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Number> tmp19;
    TNode<Float64T> tmp20;
    ca_.Bind(&block4, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Number> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    CodeStubAssembler(state_).Return(tmp21);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp22;
    TNode<Object> tmp23;
    TNode<Number> tmp24;
    TNode<Float64T> tmp25;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25);
    CodeStubAssembler(state_).Return(tmp24);
  }
}

TF_BUILTIN(MathSinh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Sinh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathSqrt, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathTan, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Tan(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathTanh, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kX));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = Convert_float64_Number_0(state_, TNode<Number>{tmp2});
    TNode<Float64T> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Float64Tanh(TNode<Float64T>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(MathHypot, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T, Float64T, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T, Float64T, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T, Float64T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T, Float64T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT, Float64T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, Float64T, Float64T, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, Float64T, Float64T, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, Float64T, Float64T, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, Float64T, Float64T, IntPtrT, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, IntPtrT, FixedDoubleArray, BoolT, Float64T, Float64T, Float64T, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp2);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block1, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    arguments.PopAndReturn(tmp13);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<IntPtrT> tmp19;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<FixedDoubleArray> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).AllocateZeroedFixedDoubleArray(TNode<IntPtrT>{tmp19});
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<Float64T> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block5, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<NativeContext> tmp27;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<FixedDoubleArray> tmp30;
    TNode<BoolT> tmp31;
    TNode<Float64T> tmp32;
    TNode<IntPtrT> tmp33;
    ca_.Bind(&block5, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp29});
    ca_.Branch(tmp34, &block3, &block4, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp35;
    TNode<RawPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<NativeContext> tmp38;
    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<FixedDoubleArray> tmp41;
    TNode<BoolT> tmp42;
    TNode<Float64T> tmp43;
    TNode<IntPtrT> tmp44;
    ca_.Bind(&block3, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<Object> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp35}, TNode<RawPtrT>{tmp36}, TNode<IntPtrT>{tmp37}}, TNode<IntPtrT>{tmp44});
    TNode<Number> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{tmp38}, TNode<Object>{tmp45});
    TNode<Float64T> tmp47;
    USE(tmp47);
    tmp47 = Convert_float64_Number_0(state_, TNode<Number>{tmp46});
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = Float64IsNaN_0(state_, TNode<Float64T>{tmp47});
    ca_.Branch(tmp48, &block7, &block8, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp47);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp49;
    TNode<RawPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<NativeContext> tmp52;
    TNode<Object> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<FixedDoubleArray> tmp55;
    TNode<BoolT> tmp56;
    TNode<Float64T> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Float64T> tmp59;
    ca_.Bind(&block7, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp60, tmp57, tmp58, tmp59);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<FixedDoubleArray> tmp67;
    TNode<BoolT> tmp68;
    TNode<Float64T> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<Float64T> tmp71;
    ca_.Bind(&block8, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    TNode<Float64T> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T>{tmp71});
    TNode<IntPtrT> tmp73 = ca_.IntPtrConstant(FixedDoubleArray::kFloatsOffset);
    USE(tmp73);
    TNode<IntPtrT> tmp74 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp74);
    TNode<Smi>tmp75 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp67, tmp74});
    TNode<IntPtrT> tmp76;
    USE(tmp76);
    tmp76 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp75});
    TNode<UintPtrT> tmp77;
    USE(tmp77);
    tmp77 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp70});
    TNode<UintPtrT> tmp78;
    USE(tmp78);
    tmp78 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp76});
    TNode<BoolT> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp77}, TNode<UintPtrT>{tmp78});
    ca_.Branch(tmp79, &block14, &block15, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp67, tmp73, tmp76, tmp70, tmp70, tmp67, tmp73, tmp76, tmp70, tmp70);
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp80;
    TNode<RawPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<NativeContext> tmp83;
    TNode<Object> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<FixedDoubleArray> tmp86;
    TNode<BoolT> tmp87;
    TNode<Float64T> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<Float64T> tmp90;
    TNode<Float64T> tmp91;
    TNode<FixedDoubleArray> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<HeapObject> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    ca_.Bind(&block14, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    TNode<IntPtrT> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp101}, TNode<IntPtrT>{tmp102});
    TNode<IntPtrT> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp98}, TNode<IntPtrT>{tmp103});
    TNode<HeapObject> tmp105;
    USE(tmp105);
    TNode<IntPtrT> tmp106;
    USE(tmp106);
    std::tie(tmp105, tmp106) = UnsafeNewReference_float64_0(state_, TNode<HeapObject>{tmp97}, TNode<IntPtrT>{tmp104}).Flatten();
    TNode<Float64T> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp91});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp105, tmp106}, tmp107);
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T>{tmp91}, TNode<Float64T>{tmp88});
    ca_.Branch(tmp108, &block17, &block18, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91);
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<NativeContext> tmp112;
    TNode<Object> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<FixedDoubleArray> tmp115;
    TNode<BoolT> tmp116;
    TNode<Float64T> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<Float64T> tmp119;
    TNode<Float64T> tmp120;
    TNode<FixedDoubleArray> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<HeapObject> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    ca_.Bind(&block15, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp131;
    TNode<RawPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<NativeContext> tmp134;
    TNode<Object> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<FixedDoubleArray> tmp137;
    TNode<BoolT> tmp138;
    TNode<Float64T> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<Float64T> tmp141;
    TNode<Float64T> tmp142;
    ca_.Bind(&block17, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142);
    ca_.Goto(&block18, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp142, tmp140, tmp141, tmp142);
  }

  if (block18.is_used()) {
    TNode<RawPtrT> tmp143;
    TNode<RawPtrT> tmp144;
    TNode<IntPtrT> tmp145;
    TNode<NativeContext> tmp146;
    TNode<Object> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<FixedDoubleArray> tmp149;
    TNode<BoolT> tmp150;
    TNode<Float64T> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<Float64T> tmp153;
    TNode<Float64T> tmp154;
    ca_.Bind(&block18, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154);
    ca_.Goto(&block9, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp155;
    TNode<RawPtrT> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<NativeContext> tmp158;
    TNode<Object> tmp159;
    TNode<IntPtrT> tmp160;
    TNode<FixedDoubleArray> tmp161;
    TNode<BoolT> tmp162;
    TNode<Float64T> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<Float64T> tmp165;
    ca_.Bind(&block9, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165);
    TNode<IntPtrT> tmp166;
    USE(tmp166);
    tmp166 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp167;
    USE(tmp167);
    tmp167 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp164}, TNode<IntPtrT>{tmp166});
    ca_.Goto(&block5, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp167);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp168;
    TNode<RawPtrT> tmp169;
    TNode<IntPtrT> tmp170;
    TNode<NativeContext> tmp171;
    TNode<Object> tmp172;
    TNode<IntPtrT> tmp173;
    TNode<FixedDoubleArray> tmp174;
    TNode<BoolT> tmp175;
    TNode<Float64T> tmp176;
    TNode<IntPtrT> tmp177;
    ca_.Bind(&block4, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177);
    TNode<Float64T> tmp178;
    USE(tmp178);
    tmp178 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    TNode<BoolT> tmp179;
    USE(tmp179);
    tmp179 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp176}, TNode<Float64T>{tmp178});
    ca_.Branch(tmp179, &block19, &block20, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176);
  }

  if (block19.is_used()) {
    TNode<RawPtrT> tmp180;
    TNode<RawPtrT> tmp181;
    TNode<IntPtrT> tmp182;
    TNode<NativeContext> tmp183;
    TNode<Object> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<FixedDoubleArray> tmp186;
    TNode<BoolT> tmp187;
    TNode<Float64T> tmp188;
    ca_.Bind(&block19, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
    TNode<Number> tmp189;
    USE(tmp189);
    tmp189 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
    arguments.PopAndReturn(tmp189);
  }

  if (block20.is_used()) {
    TNode<RawPtrT> tmp190;
    TNode<RawPtrT> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<NativeContext> tmp193;
    TNode<Object> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<FixedDoubleArray> tmp196;
    TNode<BoolT> tmp197;
    TNode<Float64T> tmp198;
    ca_.Bind(&block20, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198);
    ca_.Branch(tmp197, &block22, &block23, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198);
  }

  if (block22.is_used()) {
    TNode<RawPtrT> tmp199;
    TNode<RawPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<NativeContext> tmp202;
    TNode<Object> tmp203;
    TNode<IntPtrT> tmp204;
    TNode<FixedDoubleArray> tmp205;
    TNode<BoolT> tmp206;
    TNode<Float64T> tmp207;
    ca_.Bind(&block22, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207);
    TNode<HeapNumber> tmp208;
    USE(tmp208);
    tmp208 = kNaN_0(state_);
    arguments.PopAndReturn(tmp208);
  }

  if (block23.is_used()) {
    TNode<RawPtrT> tmp209;
    TNode<RawPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<NativeContext> tmp212;
    TNode<Object> tmp213;
    TNode<IntPtrT> tmp214;
    TNode<FixedDoubleArray> tmp215;
    TNode<BoolT> tmp216;
    TNode<Float64T> tmp217;
    ca_.Bind(&block23, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217);
    TNode<Float64T> tmp218;
    USE(tmp218);
    tmp218 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp219;
    USE(tmp219);
    tmp219 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp217}, TNode<Float64T>{tmp218});
    ca_.Branch(tmp219, &block25, &block26, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217);
  }

  if (block25.is_used()) {
    TNode<RawPtrT> tmp220;
    TNode<RawPtrT> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<NativeContext> tmp223;
    TNode<Object> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<FixedDoubleArray> tmp226;
    TNode<BoolT> tmp227;
    TNode<Float64T> tmp228;
    ca_.Bind(&block25, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228);
    TNode<Number> tmp229;
    USE(tmp229);
    tmp229 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    arguments.PopAndReturn(tmp229);
  }

  if (block26.is_used()) {
    TNode<RawPtrT> tmp230;
    TNode<RawPtrT> tmp231;
    TNode<IntPtrT> tmp232;
    TNode<NativeContext> tmp233;
    TNode<Object> tmp234;
    TNode<IntPtrT> tmp235;
    TNode<FixedDoubleArray> tmp236;
    TNode<BoolT> tmp237;
    TNode<Float64T> tmp238;
    ca_.Bind(&block26, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238);
    TNode<Float64T> tmp239;
    USE(tmp239);
    tmp239 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<Float64T> tmp240;
    USE(tmp240);
    tmp240 = FromConstexpr_float64_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp241;
    USE(tmp241);
    tmp241 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block33, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241);
  }

  if (block30.is_used()) {
    TNode<RawPtrT> tmp242;
    TNode<RawPtrT> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<NativeContext> tmp245;
    TNode<Object> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<FixedDoubleArray> tmp248;
    TNode<BoolT> tmp249;
    TNode<Float64T> tmp250;
    ca_.Bind(&block30, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250);
    CodeStubAssembler(state_).FailAssert("Torque assert 'max > 0' failed", "src/builtins/math.tq", 433);
  }

  if (block29.is_used()) {
    TNode<RawPtrT> tmp251;
    TNode<RawPtrT> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<NativeContext> tmp254;
    TNode<Object> tmp255;
    TNode<IntPtrT> tmp256;
    TNode<FixedDoubleArray> tmp257;
    TNode<BoolT> tmp258;
    TNode<Float64T> tmp259;
    ca_.Bind(&block29, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259);
  }

  if (block33.is_used()) {
    TNode<RawPtrT> tmp260;
    TNode<RawPtrT> tmp261;
    TNode<IntPtrT> tmp262;
    TNode<NativeContext> tmp263;
    TNode<Object> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<FixedDoubleArray> tmp266;
    TNode<BoolT> tmp267;
    TNode<Float64T> tmp268;
    TNode<Float64T> tmp269;
    TNode<Float64T> tmp270;
    TNode<IntPtrT> tmp271;
    ca_.Bind(&block33, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271);
    TNode<BoolT> tmp272;
    USE(tmp272);
    tmp272 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp271}, TNode<IntPtrT>{tmp265});
    ca_.Branch(tmp272, &block31, &block32, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271);
  }

  if (block31.is_used()) {
    TNode<RawPtrT> tmp273;
    TNode<RawPtrT> tmp274;
    TNode<IntPtrT> tmp275;
    TNode<NativeContext> tmp276;
    TNode<Object> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<FixedDoubleArray> tmp279;
    TNode<BoolT> tmp280;
    TNode<Float64T> tmp281;
    TNode<Float64T> tmp282;
    TNode<Float64T> tmp283;
    TNode<IntPtrT> tmp284;
    ca_.Bind(&block31, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284);
    TNode<IntPtrT> tmp285 = ca_.IntPtrConstant(FixedDoubleArray::kFloatsOffset);
    USE(tmp285);
    TNode<IntPtrT> tmp286 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp286);
    TNode<Smi>tmp287 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp279, tmp286});
    TNode<IntPtrT> tmp288;
    USE(tmp288);
    tmp288 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp287});
    TNode<UintPtrT> tmp289;
    USE(tmp289);
    tmp289 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp284});
    TNode<UintPtrT> tmp290;
    USE(tmp290);
    tmp290 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp288});
    TNode<BoolT> tmp291;
    USE(tmp291);
    tmp291 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp289}, TNode<UintPtrT>{tmp290});
    ca_.Branch(tmp291, &block39, &block40, tmp273, tmp274, tmp275, tmp276, tmp277, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp279, tmp285, tmp288, tmp284, tmp284, tmp279, tmp285, tmp288, tmp284, tmp284);
  }

  if (block39.is_used()) {
    TNode<RawPtrT> tmp292;
    TNode<RawPtrT> tmp293;
    TNode<IntPtrT> tmp294;
    TNode<NativeContext> tmp295;
    TNode<Object> tmp296;
    TNode<IntPtrT> tmp297;
    TNode<FixedDoubleArray> tmp298;
    TNode<BoolT> tmp299;
    TNode<Float64T> tmp300;
    TNode<Float64T> tmp301;
    TNode<Float64T> tmp302;
    TNode<IntPtrT> tmp303;
    TNode<FixedDoubleArray> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<IntPtrT> tmp306;
    TNode<IntPtrT> tmp307;
    TNode<IntPtrT> tmp308;
    TNode<HeapObject> tmp309;
    TNode<IntPtrT> tmp310;
    TNode<IntPtrT> tmp311;
    TNode<IntPtrT> tmp312;
    TNode<IntPtrT> tmp313;
    ca_.Bind(&block39, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313);
    TNode<IntPtrT> tmp314;
    USE(tmp314);
    tmp314 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp315;
    USE(tmp315);
    tmp315 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp313}, TNode<IntPtrT>{tmp314});
    TNode<IntPtrT> tmp316;
    USE(tmp316);
    tmp316 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp310}, TNode<IntPtrT>{tmp315});
    TNode<HeapObject> tmp317;
    USE(tmp317);
    TNode<IntPtrT> tmp318;
    USE(tmp318);
    std::tie(tmp317, tmp318) = UnsafeNewReference_float64_0(state_, TNode<HeapObject>{tmp309}, TNode<IntPtrT>{tmp316}).Flatten();
    TNode<Float64T>tmp319 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp317, tmp318});
    TNode<Float64T> tmp320;
    USE(tmp320);
    tmp320 = CodeStubAssembler(state_).Float64Div(TNode<Float64T>{tmp319}, TNode<Float64T>{tmp300});
    TNode<Float64T> tmp321;
    USE(tmp321);
    tmp321 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T>{tmp320}, TNode<Float64T>{tmp320});
    TNode<Float64T> tmp322;
    USE(tmp322);
    tmp322 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp321}, TNode<Float64T>{tmp302});
    TNode<Float64T> tmp323;
    USE(tmp323);
    tmp323 = CodeStubAssembler(state_).Float64Add(TNode<Float64T>{tmp301}, TNode<Float64T>{tmp322});
    TNode<Float64T> tmp324;
    USE(tmp324);
    tmp324 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp323}, TNode<Float64T>{tmp301});
    TNode<Float64T> tmp325;
    USE(tmp325);
    tmp325 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T>{tmp324}, TNode<Float64T>{tmp322});
    TNode<IntPtrT> tmp326;
    USE(tmp326);
    tmp326 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp327;
    USE(tmp327);
    tmp327 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp303}, TNode<IntPtrT>{tmp326});
    ca_.Goto(&block33, tmp292, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp323, tmp325, tmp327);
  }

  if (block40.is_used()) {
    TNode<RawPtrT> tmp328;
    TNode<RawPtrT> tmp329;
    TNode<IntPtrT> tmp330;
    TNode<NativeContext> tmp331;
    TNode<Object> tmp332;
    TNode<IntPtrT> tmp333;
    TNode<FixedDoubleArray> tmp334;
    TNode<BoolT> tmp335;
    TNode<Float64T> tmp336;
    TNode<Float64T> tmp337;
    TNode<Float64T> tmp338;
    TNode<IntPtrT> tmp339;
    TNode<FixedDoubleArray> tmp340;
    TNode<IntPtrT> tmp341;
    TNode<IntPtrT> tmp342;
    TNode<IntPtrT> tmp343;
    TNode<IntPtrT> tmp344;
    TNode<HeapObject> tmp345;
    TNode<IntPtrT> tmp346;
    TNode<IntPtrT> tmp347;
    TNode<IntPtrT> tmp348;
    TNode<IntPtrT> tmp349;
    ca_.Bind(&block40, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block32.is_used()) {
    TNode<RawPtrT> tmp350;
    TNode<RawPtrT> tmp351;
    TNode<IntPtrT> tmp352;
    TNode<NativeContext> tmp353;
    TNode<Object> tmp354;
    TNode<IntPtrT> tmp355;
    TNode<FixedDoubleArray> tmp356;
    TNode<BoolT> tmp357;
    TNode<Float64T> tmp358;
    TNode<Float64T> tmp359;
    TNode<Float64T> tmp360;
    TNode<IntPtrT> tmp361;
    ca_.Bind(&block32, &tmp350, &tmp351, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361);
    TNode<Float64T> tmp362;
    USE(tmp362);
    tmp362 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T>{tmp359});
    TNode<Float64T> tmp363;
    USE(tmp363);
    tmp363 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T>{tmp362}, TNode<Float64T>{tmp358});
    TNode<Number> tmp364;
    USE(tmp364);
    tmp364 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp363});
    arguments.PopAndReturn(tmp364);
  }
}

TF_BUILTIN(MathRandom, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, Object, NativeContext> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, Object, NativeContext, FixedDoubleArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Smi, Smi, FixedDoubleArray, FixedDoubleArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::MATH_RANDOM_INDEX_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp2});
    TNode<Smi> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_Smi_0(state_, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp3, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp11}, TNode<Smi>{tmp12});
    ca_.Branch(tmp13, &block5, &block6, tmp8, tmp9, tmp11);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16);
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).RefillMathRandom(TNode<NativeContext>{tmp14});
    ca_.Goto(&block6, tmp14, tmp15, tmp17);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block6, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp20}, TNode<Smi>{tmp21});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::MATH_RANDOM_INDEX_INDEX);
    CodeStubAssembler(state_).StoreContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp23}, TNode<Object>{tmp22});
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::MATH_RANDOM_CACHE_INDEX);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp24});
    TNode<FixedDoubleArray> tmp26;
    USE(tmp26);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp26 = Cast_FixedDoubleArray_1(state_, TNode<Context>{tmp18}, TNode<Object>{tmp25}, &label0);
    ca_.Goto(&block9, tmp18, tmp19, tmp20, tmp22, tmp25, tmp18, tmp26);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp18, tmp19, tmp20, tmp22, tmp25, tmp18);
    }
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp27;
    TNode<Object> tmp28;
    TNode<Smi> tmp29;
    TNode<Smi> tmp30;
    TNode<Object> tmp31;
    TNode<NativeContext> tmp32;
    ca_.Bind(&block10, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp33;
    TNode<Object> tmp34;
    TNode<Smi> tmp35;
    TNode<Smi> tmp36;
    TNode<Object> tmp37;
    TNode<NativeContext> tmp38;
    TNode<FixedDoubleArray> tmp39;
    ca_.Bind(&block9, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40 = ca_.IntPtrConstant(FixedDoubleArray::kFloatsOffset);
    USE(tmp40);
    TNode<IntPtrT> tmp41 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp41);
    TNode<Smi>tmp42 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp39, tmp41});
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp42});
    TNode<IntPtrT> tmp44;
    USE(tmp44);
    tmp44 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp36});
    TNode<UintPtrT> tmp45;
    USE(tmp45);
    tmp45 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp44});
    TNode<UintPtrT> tmp46;
    USE(tmp46);
    tmp46 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp43});
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp45}, TNode<UintPtrT>{tmp46});
    ca_.Branch(tmp47, &block15, &block16, tmp33, tmp34, tmp35, tmp36, tmp39, tmp39, tmp40, tmp43, tmp44, tmp44, tmp39, tmp40, tmp43, tmp44, tmp44);
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp48;
    TNode<Object> tmp49;
    TNode<Smi> tmp50;
    TNode<Smi> tmp51;
    TNode<FixedDoubleArray> tmp52;
    TNode<FixedDoubleArray> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<HeapObject> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    ca_.Bind(&block15, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    TNode<IntPtrT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp63});
    TNode<IntPtrT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp59}, TNode<IntPtrT>{tmp64});
    TNode<HeapObject> tmp66;
    USE(tmp66);
    TNode<IntPtrT> tmp67;
    USE(tmp67);
    std::tie(tmp66, tmp67) = UnsafeNewReference_float64_0(state_, TNode<HeapObject>{tmp58}, TNode<IntPtrT>{tmp65}).Flatten();
    TNode<Float64T>tmp68 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp66, tmp67});
    TNode<HeapNumber> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp68});
    CodeStubAssembler(state_).Return(tmp69);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp70;
    TNode<Object> tmp71;
    TNode<Smi> tmp72;
    TNode<Smi> tmp73;
    TNode<FixedDoubleArray> tmp74;
    TNode<FixedDoubleArray> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<HeapObject> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    ca_.Bind(&block16, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    CodeStubAssembler(state_).Unreachable();
  }
}

TNode<FixedDoubleArray> Cast_FixedDoubleArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, FixedDoubleArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, FixedDoubleArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<FixedDoubleArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<FixedDoubleArray> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<FixedDoubleArray> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<FixedDoubleArray>{tmp20};
}

}  // namespace internal
}  // namespace v8

