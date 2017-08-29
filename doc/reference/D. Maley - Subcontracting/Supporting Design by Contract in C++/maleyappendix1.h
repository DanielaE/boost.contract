// Appendix 1. Templates for methods with one and two formal parameters.

// Templates for methods with one and two formal parameters.
template <typename ReturnType, typename Formal1, int MethodNumber=0>
class DBC1 {
  template <typename Derived, bool Top=false, typename Terminator = typename Derived::Base>
  class DBC : public ::DBC1<ReturnType, Formal1, MethodNumber>::DBC<typename Derived::Base, false, typename Derived::Base::Base> {
    typedef ReturnType (Derived::* BodyType)(const Formal1&);
    typedef typename Derived::Base BaseType; 
    typedef ReturnType (BaseType::* AncestorBodyType)(const Formal1&);
    typedef typename ::DBC1<ReturnType, Formal1, MethodNumber>::DBC<Derived, Top, Terminator> This;
    typedef typename ::DBC1<ReturnType, Formal1, MethodNumber>::DBC<typename Derived::Base, false, typename Derived::Base::Base> Ancestor;
    bool pre(const Formal1&) const { return true; }
    void preFailure() const { throw Assertion("preFailure", __FILE__, __LINE__); }
    bool post(const ReturnType&, const Formal1&) const { return true; }
    void postFailure() const { throw Assertion("postFailure", __FILE__, __LINE__); }
Appendix 1. Templates for methods with one and two formal parameters (continued).

    BodyType _body;
    void handleOld(const Derived*);
    const Derived* _object;
    Derived* _mutableObject;
  protected:
    bool effectivePre(const Formal1& f1) const { return Ancestor::effectivePre(f1) || This::pre(f1); }
  
 bool effectivePost(const ReturnType& t, const Formal1& f1) const { return Ancestor::effectivePost(t, f1) && This::post(t, f1); }
    bool effectiveInvariant() const { return Ancestor::effectiveInvariant() && This::_object->invariant(); }
    const Derived* old() const { return static_cast<const Derived*>(Ancestor::old()); }
  public:
    DBC(Derived* object, BodyType body) : _body(body), _mutableObject(object), _object(object), Ancestor(object, static_cast<AncestorBodyType>(body)) { handleOld(object); }
    ReturnType operator()(const Formal1&);
  };

  template <typename Derived>
  class DBC<Derived, false, Derived> {
    typedef ReturnType (Derived::* BodyType)(const Formal1&);
    typedef typename ::DBC1<ReturnType, Formal1, MethodNumber>::DBC<Derived, false, Derived> This;
    bool pre(const Formal1&) const { return true; }
    void preFailure() const { throw Assertion("preFailure", __FILE__, __LINE__); }
    bool post(const ReturnType&, const Formal1&) const { return true; }
    void postFailure() const { throw Assertion("postFailure", __FILE__, __LINE__); }
    BodyType _body;
    const Derived* _object;
    Derived* _mutableObject;
  protected:
    bool effectivePre(const Formal1& f1) const { return This::pre(f1); }
    bool effectivePost(const ReturnType& t, const Formal1& f1) const { return This::post(t, f1); }
    bool effectiveInvariant() const { return This::_object->invariant(); }
    const Derived* const old() const { return _old; }
    const Derived* _old;
  public:
    DBC(Derived* object, BodyType body) : _body(body), _mutableObject(object), _object(object), _old(NULL) { }
    ReturnType operator()(const Formal1&);
  };
};

template <typename ReturnType, typename Formal1, int MethodNumber>
  template <typename Derived, bool Top, typename Terminator>
    void DBC1<ReturnType, Formal1, MethodNumber>::DBC<Derived, Top, Terminator>::handleOld(const Derived* dp)
    {
      if (Top) {
        if (_old)
          delete _old;
        _old = new Derived(*dp);
      }
    }
    
template <typename ReturnType, typename Formal1, int MethodNumber>
  template <typename Derived, bool Top, typename Terminator>
    ReturnType DBC1<ReturnType, Formal1, MethodNumber>::DBC<Derived, Top, Terminator>::operator()(const Formal1& f1)
    {
      if (!effectivePre(f1) || !effectiveInvariant())
Appendix 1. Templates for methods with one and two formal parameters (continued).

        preFailure();
      handleOld(_object);
      ReturnType result=(_mutableObject->*_body)(f1)
      if (!effectivePost(result, f1) || !effectiveInvariant())
        postFailure();
 
  return result;
    }
    
template <typename ReturnType, typename Formal1, int MethodNumber>
  template <typename Derived>
    ReturnType DBC1<ReturnType, Formal1, MethodNumber>::DBC<Derived, false, Derived>::operator()(const Formal1& f1)
    {
      if (!effectivePre(f1) || !effectiveInvariant())
        preFailure();
      ReturnType result=(_mutableObject->*_body)(f1);
      if (!effectivePost(result, f1) || !effectiveInvariant())
        postFailure();
      return result;
    }
    
template <typename ReturnType, typename Formal1, typename Formal2, int MethodNumber=0>
class DBC2 {
  template <typename Derived, bool Top=false, typename Terminator = typename Derived::Base>
  class DBC : public ::DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<typename Derived::Base, false, typename Derived::Base::Base> {
    typedef ReturnType (Derived::* BodyType)(const Formal1&, const Formal2&);
    typedef typename Derived::Base BaseType; 
    typedef ReturnType (BaseType::* AncestorBodyType)(const Formal1&, const Formal2&);
    typedef typename ::DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<Derived, Top, Terminator> This;
    typedef typename ::DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<typename Derived::Base, false, typename Derived::Base::Base> Ancestor;
    bool pre(const Formal1&, const Formal2&) const { return true; }
    void preFailure() const { throw Assertion("preFailure", __FILE__, __LINE__); }
    bool post(const ReturnType&, const Formal1&, const Formal2&) const { return true; }
    void postFailure() const { throw Assertion("postFailure", __FILE__, __LINE__); }
    BodyType _body;
    void handleOld(const Derived*);
    const Derived* _object;
    Derived* _mutableObject;
  protected:
    bool effectivePre(const Formal1& f1, const Formal2& f2) const { return Ancestor::effectivePre(f1, f2) || This::pre(f1, f2); }
    bool effectivePost(const ReturnType& t, const Formal1& f1, const Formal2& f2) const { return Ancestor::effectivePost(t, f1, f2) && This::post(t, f1, f2); }
    bool effectiveInvariant() const { return Ancestor::effectiveInvariant() && This::_object->invariant(); }
    const Derived* old() const { return static_cast<const Derived*>(Ancestor::old()); }
  public:
    DBC(Derived* object, BodyType body) : _body(body), _mutableObject(object), _object(object), Ancestor(object, static_cast<AncestorBodyType>(body)) { handleOld(object); }
    ReturnType operator()(const Formal1&, const Formal2&);
  };

  template <typename Derived>
  class DBC<Derived, false, Derived> {
    typedef ReturnType (Derived::* BodyType)(const Formal1&, const Formal2&);
    typedef typename ::DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<Derived, false, Derived> This;
Appendix 1. Templates for methods with one and two formal parameters (continued).

    bool pre(const Formal1&, const Formal2&) const { return true; }
    void preFailure() const { throw Assertion("preFailure", __FILE__, __LINE__); }
    bool post(const ReturnType&, const Formal1&, const Formal2&) const { return true; }
    void postFailure() const { throw Assertion("postFailure", __FILE__, __LINE__); }
    BodyType _body;

 const Derived* _object;
    Derived* _mutableObject;
  protected:
    bool effectivePre(const Formal1& f1, const Formal2& f2) const { return This::pre(f1, f2); }
    bool effectivePost(const ReturnType& t, const Formal1& f1, const Formal2& f2) const { return This::post(t, f1, f2); }
    bool effectiveInvariant() const { return This::_object->invariant(); }
    const Derived* const old() const { return _old; }
    const Derived* _old;
  public:
    DBC(Derived* object, BodyType body) : _body(body), _mutableObject(object), _object(object), _old(NULL) { }
    ReturnType operator()(const Formal1&, const Formal2&);
  };
};

template <typename ReturnType, typename Formal1, typename Formal2, int MethodNumber>
  template <typename Derived, bool Top, typename Terminator>
    void DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<Derived, Top, Terminator>::handleOld(const Derived* dp)
    {
      if (Top) {
        if (_old)
          delete _old;
        _old = new Derived(*dp);
      }
    }
    
template <typename ReturnType, typename Formal1, typename Formal2, int MethodNumber>
  template <typename Derived, bool Top, typename Terminator>
    ReturnType DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<Derived, Top, Terminator>::operator()(const Formal1& f1, const Formal2& f2)
    {
      if (!effectivePre(f1, f2) || !effectiveInvariant())
        preFailure();
      handleOld(_object);
      ReturnType result=(_mutableObject->*_body)(f1, f2);
      if (!effectivePost(result, f1, f2) || !effectiveInvariant())
        postFailure();
      return result;
    }
    template <typename ReturnType, typename Formal1, typename Formal2, int MethodNumber>
  template <typename Derived>
    ReturnType DBC2<ReturnType, Formal1, Formal2, MethodNumber>::DBC<Derived, false, Derived>::operator()(const Formal1& f1, const Formal2& f2)
    {
      if (!effectivePre(f1, f2) || !effectiveInvariant())
        preFailure();
      ReturnType result=(_mutableObject->*_body)(f1, f2);
      if (!effectivePost(result, f1, f2) || !effectiveInvariant())
        postFailure();
      return result;
    }
