# Fegn 2.3.1-Prime

Fegn, Wholf dilinde entegrasyon ve veri yönetimi için kullanılan en gelişmiş kütüphanedir.

## Yeni Özellikler

- Asenkron programlama
- Stream desteği
- Event sourcing
- Gelişmiş performans
- WebSocket protokolü desteği
- Gelişmiş cache algoritmaları
- Veri doğrulama kuralları
- Hata yönetimi stratejileri

## Kurulum

```wholf
fort import "Fegn-2.3.1-Prime"
```

## Kullanım Örnekleri

### Asenkron Programlama

```wholf
// Asenkron fonksiyon
async function getData() {
    var response = await Api.get("/data")
    return response.data
}

// Asenkron fonksiyon kullanımı
async function main() {
    var data = await getData()
    Console.log("Veri: " + data)
}
```

### Stream

```wholf
// Stream oluşturma
fegn Stream {
    // Veri akışı
    pipe: (data) => {
        // Veri işleme
        return data
    },
    
    // Hata yönetimi
    onError: (error) => {
        Console.log("Hata: " + error)
    }
}
```

### Event Sourcing

```wholf
// Event sourcing
fegn EventSource {
    // Event oluşturma
    createEvent: (type, data) => {
        return {
            type: type,
            data: data,
            timestamp: Date.now()
        }
    },
    
    // Event kaydetme
    storeEvent: (event) => {
        // Event kaydet
    }
}
```

## Lisans

MIT License
