// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: response.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_response_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_response_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3010000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3010001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_response_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_response_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_response_2eproto;
namespace colly {
class Headers;
class HeadersDefaultTypeInternal;
extern HeadersDefaultTypeInternal _Headers_default_instance_;
class Parsed;
class ParsedDefaultTypeInternal;
extern ParsedDefaultTypeInternal _Parsed_default_instance_;
class Response;
class ResponseDefaultTypeInternal;
extern ResponseDefaultTypeInternal _Response_default_instance_;
class Response_HeadersEntry_DoNotUse;
class Response_HeadersEntry_DoNotUseDefaultTypeInternal;
extern Response_HeadersEntry_DoNotUseDefaultTypeInternal _Response_HeadersEntry_DoNotUse_default_instance_;
}  // namespace colly
PROTOBUF_NAMESPACE_OPEN
template<> ::colly::Headers* Arena::CreateMaybeMessage<::colly::Headers>(Arena*);
template<> ::colly::Parsed* Arena::CreateMaybeMessage<::colly::Parsed>(Arena*);
template<> ::colly::Response* Arena::CreateMaybeMessage<::colly::Response>(Arena*);
template<> ::colly::Response_HeadersEntry_DoNotUse* Arena::CreateMaybeMessage<::colly::Response_HeadersEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace colly {

// ===================================================================

class Parsed :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:colly.Parsed) */ {
 public:
  Parsed();
  virtual ~Parsed();

  Parsed(const Parsed& from);
  Parsed(Parsed&& from) noexcept
    : Parsed() {
    *this = ::std::move(from);
  }

  inline Parsed& operator=(const Parsed& from) {
    CopyFrom(from);
    return *this;
  }
  inline Parsed& operator=(Parsed&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Parsed& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Parsed* internal_default_instance() {
    return reinterpret_cast<const Parsed*>(
               &_Parsed_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Parsed& a, Parsed& b) {
    a.Swap(&b);
  }
  inline void Swap(Parsed* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Parsed* New() const final {
    return CreateMaybeMessage<Parsed>(nullptr);
  }

  Parsed* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Parsed>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Parsed& from);
  void MergeFrom(const Parsed& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Parsed* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "colly.Parsed";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_response_2eproto);
    return ::descriptor_table_response_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNexturlFieldNumber = 1,
  };
  // string nexturl = 1;
  void clear_nexturl();
  const std::string& nexturl() const;
  void set_nexturl(const std::string& value);
  void set_nexturl(std::string&& value);
  void set_nexturl(const char* value);
  void set_nexturl(const char* value, size_t size);
  std::string* mutable_nexturl();
  std::string* release_nexturl();
  void set_allocated_nexturl(std::string* nexturl);
  private:
  const std::string& _internal_nexturl() const;
  void _internal_set_nexturl(const std::string& value);
  std::string* _internal_mutable_nexturl();
  public:

  // @@protoc_insertion_point(class_scope:colly.Parsed)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nexturl_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_response_2eproto;
};
// -------------------------------------------------------------------

class Response_HeadersEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Response_HeadersEntry_DoNotUse, 
    std::string, ::colly::Headers,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Response_HeadersEntry_DoNotUse, 
    std::string, ::colly::Headers,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > SuperType;
  Response_HeadersEntry_DoNotUse();
  Response_HeadersEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const Response_HeadersEntry_DoNotUse& other);
  static const Response_HeadersEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const Response_HeadersEntry_DoNotUse*>(&_Response_HeadersEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), s->size(), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "colly.Response.HeadersEntry.key");
 }
  static bool ValidateValue(void*) { return true; }
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& other) final;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_response_2eproto);
    return ::descriptor_table_response_2eproto.file_level_metadata[1];
  }

  public:
};

// -------------------------------------------------------------------

class Response :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:colly.Response) */ {
 public:
  Response();
  virtual ~Response();

  Response(const Response& from);
  Response(Response&& from) noexcept
    : Response() {
    *this = ::std::move(from);
  }

  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }
  inline Response& operator=(Response&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Response& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Response* internal_default_instance() {
    return reinterpret_cast<const Response*>(
               &_Response_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Response& a, Response& b) {
    a.Swap(&b);
  }
  inline void Swap(Response* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Response* New() const final {
    return CreateMaybeMessage<Response>(nullptr);
  }

  Response* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Response>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Response* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "colly.Response";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_response_2eproto);
    return ::descriptor_table_response_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kHeadersFieldNumber = 5,
    kBodyFieldNumber = 2,
    kStatusCodeFieldNumber = 1,
  };
  // map<string, .colly.Headers> Headers = 5;
  int headers_size() const;
  private:
  int _internal_headers_size() const;
  public:
  void clear_headers();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >&
      _internal_headers() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >*
      _internal_mutable_headers();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >&
      headers() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >*
      mutable_headers();

  // bytes Body = 2;
  void clear_body();
  const std::string& body() const;
  void set_body(const std::string& value);
  void set_body(std::string&& value);
  void set_body(const char* value);
  void set_body(const void* value, size_t size);
  std::string* mutable_body();
  std::string* release_body();
  void set_allocated_body(std::string* body);
  private:
  const std::string& _internal_body() const;
  void _internal_set_body(const std::string& value);
  std::string* _internal_mutable_body();
  public:

  // int32 StatusCode = 1;
  void clear_statuscode();
  ::PROTOBUF_NAMESPACE_ID::int32 statuscode() const;
  void set_statuscode(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_statuscode() const;
  void _internal_set_statuscode(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:colly.Response)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::MapField<
      Response_HeadersEntry_DoNotUse,
      std::string, ::colly::Headers,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
      0 > headers_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr body_;
  ::PROTOBUF_NAMESPACE_ID::int32 statuscode_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_response_2eproto;
};
// -------------------------------------------------------------------

class Headers :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:colly.Headers) */ {
 public:
  Headers();
  virtual ~Headers();

  Headers(const Headers& from);
  Headers(Headers&& from) noexcept
    : Headers() {
    *this = ::std::move(from);
  }

  inline Headers& operator=(const Headers& from) {
    CopyFrom(from);
    return *this;
  }
  inline Headers& operator=(Headers&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Headers& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Headers* internal_default_instance() {
    return reinterpret_cast<const Headers*>(
               &_Headers_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(Headers& a, Headers& b) {
    a.Swap(&b);
  }
  inline void Swap(Headers* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Headers* New() const final {
    return CreateMaybeMessage<Headers>(nullptr);
  }

  Headers* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Headers>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Headers& from);
  void MergeFrom(const Headers& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Headers* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "colly.Headers";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_response_2eproto);
    return ::descriptor_table_response_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValFieldNumber = 1,
  };
  // repeated string Val = 1;
  int val_size() const;
  private:
  int _internal_val_size() const;
  public:
  void clear_val();
  const std::string& val(int index) const;
  std::string* mutable_val(int index);
  void set_val(int index, const std::string& value);
  void set_val(int index, std::string&& value);
  void set_val(int index, const char* value);
  void set_val(int index, const char* value, size_t size);
  std::string* add_val();
  void add_val(const std::string& value);
  void add_val(std::string&& value);
  void add_val(const char* value);
  void add_val(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& val() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_val();
  private:
  const std::string& _internal_val(int index) const;
  std::string* _internal_add_val();
  public:

  // @@protoc_insertion_point(class_scope:colly.Headers)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> val_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_response_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Parsed

// string nexturl = 1;
inline void Parsed::clear_nexturl() {
  nexturl_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Parsed::nexturl() const {
  // @@protoc_insertion_point(field_get:colly.Parsed.nexturl)
  return _internal_nexturl();
}
inline void Parsed::set_nexturl(const std::string& value) {
  _internal_set_nexturl(value);
  // @@protoc_insertion_point(field_set:colly.Parsed.nexturl)
}
inline std::string* Parsed::mutable_nexturl() {
  // @@protoc_insertion_point(field_mutable:colly.Parsed.nexturl)
  return _internal_mutable_nexturl();
}
inline const std::string& Parsed::_internal_nexturl() const {
  return nexturl_.GetNoArena();
}
inline void Parsed::_internal_set_nexturl(const std::string& value) {
  
  nexturl_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Parsed::set_nexturl(std::string&& value) {
  
  nexturl_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:colly.Parsed.nexturl)
}
inline void Parsed::set_nexturl(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  nexturl_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:colly.Parsed.nexturl)
}
inline void Parsed::set_nexturl(const char* value, size_t size) {
  
  nexturl_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:colly.Parsed.nexturl)
}
inline std::string* Parsed::_internal_mutable_nexturl() {
  
  return nexturl_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Parsed::release_nexturl() {
  // @@protoc_insertion_point(field_release:colly.Parsed.nexturl)
  
  return nexturl_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Parsed::set_allocated_nexturl(std::string* nexturl) {
  if (nexturl != nullptr) {
    
  } else {
    
  }
  nexturl_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), nexturl);
  // @@protoc_insertion_point(field_set_allocated:colly.Parsed.nexturl)
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// Response

// int32 StatusCode = 1;
inline void Response::clear_statuscode() {
  statuscode_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Response::_internal_statuscode() const {
  return statuscode_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Response::statuscode() const {
  // @@protoc_insertion_point(field_get:colly.Response.StatusCode)
  return _internal_statuscode();
}
inline void Response::_internal_set_statuscode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  statuscode_ = value;
}
inline void Response::set_statuscode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_statuscode(value);
  // @@protoc_insertion_point(field_set:colly.Response.StatusCode)
}

// bytes Body = 2;
inline void Response::clear_body() {
  body_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Response::body() const {
  // @@protoc_insertion_point(field_get:colly.Response.Body)
  return _internal_body();
}
inline void Response::set_body(const std::string& value) {
  _internal_set_body(value);
  // @@protoc_insertion_point(field_set:colly.Response.Body)
}
inline std::string* Response::mutable_body() {
  // @@protoc_insertion_point(field_mutable:colly.Response.Body)
  return _internal_mutable_body();
}
inline const std::string& Response::_internal_body() const {
  return body_.GetNoArena();
}
inline void Response::_internal_set_body(const std::string& value) {
  
  body_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Response::set_body(std::string&& value) {
  
  body_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:colly.Response.Body)
}
inline void Response::set_body(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  body_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:colly.Response.Body)
}
inline void Response::set_body(const void* value, size_t size) {
  
  body_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:colly.Response.Body)
}
inline std::string* Response::_internal_mutable_body() {
  
  return body_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Response::release_body() {
  // @@protoc_insertion_point(field_release:colly.Response.Body)
  
  return body_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Response::set_allocated_body(std::string* body) {
  if (body != nullptr) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:colly.Response.Body)
}

// map<string, .colly.Headers> Headers = 5;
inline int Response::_internal_headers_size() const {
  return headers_.size();
}
inline int Response::headers_size() const {
  return _internal_headers_size();
}
inline void Response::clear_headers() {
  headers_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >&
Response::_internal_headers() const {
  return headers_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >&
Response::headers() const {
  // @@protoc_insertion_point(field_map:colly.Response.Headers)
  return _internal_headers();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >*
Response::_internal_mutable_headers() {
  return headers_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::colly::Headers >*
Response::mutable_headers() {
  // @@protoc_insertion_point(field_mutable_map:colly.Response.Headers)
  return _internal_mutable_headers();
}

// -------------------------------------------------------------------

// Headers

// repeated string Val = 1;
inline int Headers::_internal_val_size() const {
  return val_.size();
}
inline int Headers::val_size() const {
  return _internal_val_size();
}
inline void Headers::clear_val() {
  val_.Clear();
}
inline std::string* Headers::add_val() {
  // @@protoc_insertion_point(field_add_mutable:colly.Headers.Val)
  return _internal_add_val();
}
inline const std::string& Headers::_internal_val(int index) const {
  return val_.Get(index);
}
inline const std::string& Headers::val(int index) const {
  // @@protoc_insertion_point(field_get:colly.Headers.Val)
  return _internal_val(index);
}
inline std::string* Headers::mutable_val(int index) {
  // @@protoc_insertion_point(field_mutable:colly.Headers.Val)
  return val_.Mutable(index);
}
inline void Headers::set_val(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:colly.Headers.Val)
  val_.Mutable(index)->assign(value);
}
inline void Headers::set_val(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:colly.Headers.Val)
  val_.Mutable(index)->assign(std::move(value));
}
inline void Headers::set_val(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  val_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:colly.Headers.Val)
}
inline void Headers::set_val(int index, const char* value, size_t size) {
  val_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:colly.Headers.Val)
}
inline std::string* Headers::_internal_add_val() {
  return val_.Add();
}
inline void Headers::add_val(const std::string& value) {
  val_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:colly.Headers.Val)
}
inline void Headers::add_val(std::string&& value) {
  val_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:colly.Headers.Val)
}
inline void Headers::add_val(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  val_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:colly.Headers.Val)
}
inline void Headers::add_val(const char* value, size_t size) {
  val_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:colly.Headers.Val)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Headers::val() const {
  // @@protoc_insertion_point(field_list:colly.Headers.Val)
  return val_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Headers::mutable_val() {
  // @@protoc_insertion_point(field_mutable_list:colly.Headers.Val)
  return &val_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace colly

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_response_2eproto
