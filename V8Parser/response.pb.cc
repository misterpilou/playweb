// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: response.proto

#include "response.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_response_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Headers_response_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_response_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Response_HeadersEntry_DoNotUse_response_2eproto;
namespace colly {
class ParsedDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Parsed> _instance;
} _Parsed_default_instance_;
class Response_HeadersEntry_DoNotUseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Response_HeadersEntry_DoNotUse> _instance;
} _Response_HeadersEntry_DoNotUse_default_instance_;
class ResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Response> _instance;
} _Response_default_instance_;
class HeadersDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Headers> _instance;
} _Headers_default_instance_;
}  // namespace colly
static void InitDefaultsscc_info_Headers_response_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::colly::_Headers_default_instance_;
    new (ptr) ::colly::Headers();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::colly::Headers::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Headers_response_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Headers_response_2eproto}, {}};

static void InitDefaultsscc_info_Parsed_response_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::colly::_Parsed_default_instance_;
    new (ptr) ::colly::Parsed();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::colly::Parsed::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Parsed_response_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Parsed_response_2eproto}, {}};

static void InitDefaultsscc_info_Response_response_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::colly::_Response_default_instance_;
    new (ptr) ::colly::Response();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::colly::Response::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Response_response_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Response_response_2eproto}, {
      &scc_info_Response_HeadersEntry_DoNotUse_response_2eproto.base,}};

static void InitDefaultsscc_info_Response_HeadersEntry_DoNotUse_response_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::colly::_Response_HeadersEntry_DoNotUse_default_instance_;
    new (ptr) ::colly::Response_HeadersEntry_DoNotUse();
  }
  ::colly::Response_HeadersEntry_DoNotUse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Response_HeadersEntry_DoNotUse_response_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Response_HeadersEntry_DoNotUse_response_2eproto}, {
      &scc_info_Headers_response_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_response_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_response_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_response_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_response_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::colly::Parsed, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::colly::Parsed, nexturl_),
  PROTOBUF_FIELD_OFFSET(::colly::Response_HeadersEntry_DoNotUse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::colly::Response_HeadersEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::colly::Response_HeadersEntry_DoNotUse, key_),
  PROTOBUF_FIELD_OFFSET(::colly::Response_HeadersEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::colly::Response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::colly::Response, statuscode_),
  PROTOBUF_FIELD_OFFSET(::colly::Response, body_),
  PROTOBUF_FIELD_OFFSET(::colly::Response, headers_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::colly::Headers, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::colly::Headers, val_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::colly::Parsed)},
  { 6, 13, sizeof(::colly::Response_HeadersEntry_DoNotUse)},
  { 15, -1, sizeof(::colly::Response)},
  { 23, -1, sizeof(::colly::Headers)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::colly::_Parsed_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::colly::_Response_HeadersEntry_DoNotUse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::colly::_Response_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::colly::_Headers_default_instance_),
};

const char descriptor_table_protodef_response_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016response.proto\022\005colly\"\031\n\006Parsed\022\017\n\007nex"
  "turl\030\001 \001(\t\"\233\001\n\010Response\022\022\n\nStatusCode\030\001 "
  "\001(\005\022\014\n\004Body\030\002 \001(\014\022-\n\007Headers\030\005 \003(\0132\034.col"
  "ly.Response.HeadersEntry\032>\n\014HeadersEntry"
  "\022\013\n\003key\030\001 \001(\t\022\035\n\005value\030\002 \001(\0132\016.colly.Hea"
  "ders:\0028\001\"\026\n\007Headers\022\013\n\003Val\030\001 \003(\t2;\n\006Pars"
  "er\0221\n\rParseResponse\022\017.colly.Response\032\r.c"
  "olly.Parsed\"\000B\007Z\005collyb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_response_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_response_2eproto_sccs[4] = {
  &scc_info_Headers_response_2eproto.base,
  &scc_info_Parsed_response_2eproto.base,
  &scc_info_Response_response_2eproto.base,
  &scc_info_Response_HeadersEntry_DoNotUse_response_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_response_2eproto_once;
static bool descriptor_table_response_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_response_2eproto = {
  &descriptor_table_response_2eproto_initialized, descriptor_table_protodef_response_2eproto, "response.proto", 310,
  &descriptor_table_response_2eproto_once, descriptor_table_response_2eproto_sccs, descriptor_table_response_2eproto_deps, 4, 0,
  schemas, file_default_instances, TableStruct_response_2eproto::offsets,
  file_level_metadata_response_2eproto, 4, file_level_enum_descriptors_response_2eproto, file_level_service_descriptors_response_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_response_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_response_2eproto), true);
namespace colly {

// ===================================================================

void Parsed::InitAsDefaultInstance() {
}
class Parsed::_Internal {
 public:
};

Parsed::Parsed()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:colly.Parsed)
}
Parsed::Parsed(const Parsed& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  nexturl_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_nexturl().empty()) {
    nexturl_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.nexturl_);
  }
  // @@protoc_insertion_point(copy_constructor:colly.Parsed)
}

void Parsed::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Parsed_response_2eproto.base);
  nexturl_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Parsed::~Parsed() {
  // @@protoc_insertion_point(destructor:colly.Parsed)
  SharedDtor();
}

void Parsed::SharedDtor() {
  nexturl_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Parsed::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Parsed& Parsed::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Parsed_response_2eproto.base);
  return *internal_default_instance();
}


void Parsed::Clear() {
// @@protoc_insertion_point(message_clear_start:colly.Parsed)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  nexturl_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* Parsed::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string nexturl = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_nexturl(), ptr, ctx, "colly.Parsed.nexturl");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Parsed::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:colly.Parsed)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string nexturl = 1;
  if (this->nexturl().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_nexturl().data(), static_cast<int>(this->_internal_nexturl().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "colly.Parsed.nexturl");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_nexturl(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:colly.Parsed)
  return target;
}

size_t Parsed::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:colly.Parsed)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string nexturl = 1;
  if (this->nexturl().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_nexturl());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Parsed::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:colly.Parsed)
  GOOGLE_DCHECK_NE(&from, this);
  const Parsed* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Parsed>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:colly.Parsed)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:colly.Parsed)
    MergeFrom(*source);
  }
}

void Parsed::MergeFrom(const Parsed& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:colly.Parsed)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.nexturl().size() > 0) {

    nexturl_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.nexturl_);
  }
}

void Parsed::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:colly.Parsed)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Parsed::CopyFrom(const Parsed& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:colly.Parsed)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Parsed::IsInitialized() const {
  return true;
}

void Parsed::InternalSwap(Parsed* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  nexturl_.Swap(&other->nexturl_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata Parsed::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

Response_HeadersEntry_DoNotUse::Response_HeadersEntry_DoNotUse() {}
Response_HeadersEntry_DoNotUse::Response_HeadersEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void Response_HeadersEntry_DoNotUse::MergeFrom(const Response_HeadersEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata Response_HeadersEntry_DoNotUse::GetMetadata() const {
  return GetMetadataStatic();
}
void Response_HeadersEntry_DoNotUse::MergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::Message& other) {
  ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom(other);
}


// ===================================================================

void Response::InitAsDefaultInstance() {
}
class Response::_Internal {
 public:
};

Response::Response()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:colly.Response)
}
Response::Response(const Response& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  headers_.MergeFrom(from.headers_);
  body_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_body().empty()) {
    body_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
  statuscode_ = from.statuscode_;
  // @@protoc_insertion_point(copy_constructor:colly.Response)
}

void Response::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Response_response_2eproto.base);
  body_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  statuscode_ = 0;
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:colly.Response)
  SharedDtor();
}

void Response::SharedDtor() {
  body_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Response& Response::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Response_response_2eproto.base);
  return *internal_default_instance();
}


void Response::Clear() {
// @@protoc_insertion_point(message_clear_start:colly.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  headers_.Clear();
  body_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  statuscode_ = 0;
  _internal_metadata_.Clear();
}

const char* Response::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 StatusCode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          statuscode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes Body = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(_internal_mutable_body(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // map<string, .colly.Headers> Headers = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(&headers_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Response::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:colly.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 StatusCode = 1;
  if (this->statuscode() != 0) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_statuscode(), target);
  }

  // bytes Body = 2;
  if (this->body().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_body(), target);
  }

  // map<string, .colly.Headers> Headers = 5;
  if (!this->_internal_headers().empty()) {
    typedef ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >::const_pointer
        ConstPtr;
    typedef ConstPtr SortItem;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::CompareByDerefFirst<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          p->first.data(), static_cast<int>(p->first.length()),
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
          "colly.Response.HeadersEntry.key");
      }
    };

    if (stream->IsSerializationDeterministic() &&
        this->_internal_headers().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->_internal_headers().size()]);
      typedef ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >::size_type size_type;
      size_type n = 0;
      for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >::const_iterator
          it = this->_internal_headers().begin();
          it != this->_internal_headers().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      for (size_type i = 0; i < n; i++) {
        target = Response_HeadersEntry_DoNotUse::Funcs::InternalSerialize(5, items[static_cast<ptrdiff_t>(i)]->first, items[static_cast<ptrdiff_t>(i)]->second, target, stream);
        Utf8Check::Check(&(*items[static_cast<ptrdiff_t>(i)]));
      }
    } else {
      for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >::const_iterator
          it = this->_internal_headers().begin();
          it != this->_internal_headers().end(); ++it) {
        target = Response_HeadersEntry_DoNotUse::Funcs::InternalSerialize(5, it->first, it->second, target, stream);
        Utf8Check::Check(&(*it));
      }
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:colly.Response)
  return target;
}

size_t Response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:colly.Response)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // map<string, .colly.Headers> Headers = 5;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_headers_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >::const_iterator
      it = this->_internal_headers().begin();
      it != this->_internal_headers().end(); ++it) {
    total_size += Response_HeadersEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // bytes Body = 2;
  if (this->body().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_body());
  }

  // int32 StatusCode = 1;
  if (this->statuscode() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_statuscode());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Response::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:colly.Response)
  GOOGLE_DCHECK_NE(&from, this);
  const Response* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Response>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:colly.Response)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:colly.Response)
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:colly.Response)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  headers_.MergeFrom(from.headers_);
  if (from.body().size() > 0) {

    body_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
  if (from.statuscode() != 0) {
    _internal_set_statuscode(from._internal_statuscode());
  }
}

void Response::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:colly.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:colly.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  return true;
}

void Response::InternalSwap(Response* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  headers_.Swap(&other->headers_);
  body_.Swap(&other->body_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(statuscode_, other->statuscode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Response::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Headers::InitAsDefaultInstance() {
}
class Headers::_Internal {
 public:
};

Headers::Headers()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:colly.Headers)
}
Headers::Headers(const Headers& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      val_(from.val_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:colly.Headers)
}

void Headers::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Headers_response_2eproto.base);
}

Headers::~Headers() {
  // @@protoc_insertion_point(destructor:colly.Headers)
  SharedDtor();
}

void Headers::SharedDtor() {
}

void Headers::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Headers& Headers::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Headers_response_2eproto.base);
  return *internal_default_instance();
}


void Headers::Clear() {
// @@protoc_insertion_point(message_clear_start:colly.Headers)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  val_.Clear();
  _internal_metadata_.Clear();
}

const char* Headers::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated string Val = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_add_val(), ptr, ctx, "colly.Headers.Val");
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Headers::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:colly.Headers)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated string Val = 1;
  for (int i = 0, n = this->_internal_val_size(); i < n; i++) {
    const auto& s = this->_internal_val(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "colly.Headers.Val");
    target = stream->WriteString(1, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:colly.Headers)
  return target;
}

size_t Headers::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:colly.Headers)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string Val = 1;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(val_.size());
  for (int i = 0, n = val_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      val_.Get(i));
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Headers::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:colly.Headers)
  GOOGLE_DCHECK_NE(&from, this);
  const Headers* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Headers>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:colly.Headers)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:colly.Headers)
    MergeFrom(*source);
  }
}

void Headers::MergeFrom(const Headers& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:colly.Headers)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  val_.MergeFrom(from.val_);
}

void Headers::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:colly.Headers)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Headers::CopyFrom(const Headers& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:colly.Headers)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Headers::IsInitialized() const {
  return true;
}

void Headers::InternalSwap(Headers* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  val_.InternalSwap(&other->val_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Headers::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace colly
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::colly::Parsed* Arena::CreateMaybeMessage< ::colly::Parsed >(Arena* arena) {
  return Arena::CreateInternal< ::colly::Parsed >(arena);
}
template<> PROTOBUF_NOINLINE ::colly::Response_HeadersEntry_DoNotUse* Arena::CreateMaybeMessage< ::colly::Response_HeadersEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateInternal< ::colly::Response_HeadersEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::colly::Response* Arena::CreateMaybeMessage< ::colly::Response >(Arena* arena) {
  return Arena::CreateInternal< ::colly::Response >(arena);
}
template<> PROTOBUF_NOINLINE ::colly::Headers* Arena::CreateMaybeMessage< ::colly::Headers >(Arena* arena) {
  return Arena::CreateInternal< ::colly::Headers >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
