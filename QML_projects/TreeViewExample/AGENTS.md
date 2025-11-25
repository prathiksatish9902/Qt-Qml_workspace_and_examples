# TreeViewExample Agent Guide

## Build/Run Commands
```bash
# Build project (Qt qmake)
qmake TreeViewExample.pro
make

# Run application
./TreeViewExample
```

## Architecture

**Structure:**
- **Model Layer**: `Company`, `Employee` - QObject-based data classes
- **Tree Model**: `TreeModel` (QAbstractItemModel) - hierarchical model with `TreeItem` nodes
- **UI**: `main.qml` - Qt Quick with TreeView + details panel split layout
- **TreeItem**: Internal node structure representing Company and Employee hierarchy

**Key Classes:**
- `TreeModel`: Manages tree hierarchy, custom roles (DetailsRole, TypeRole, IdRole, YearRole, ImageRole, RoleRole, EmailRole)
- `Company`: Stores id, name, year, image; contains employee collection
- `Employee`: Stores id, name, role, email

## Code Style & Conventions

**C++:**
- Use `#pragma once` for headers
- Member variables prefixed with `m_` (e.g., `m_id`, `m_name`)
- Qt signals/slots pattern (Q_OBJECT, Q_PROPERTY, Q_INVOKABLE)
- Avoid circular includes (use forward declarations)

**QML:**
- Use Layout components (RowLayout, ColumnLayout) for responsive UI
- Custom roles from model: access via role names (e.g., `role: "id"`)
- MouseArea for click handlers
- Rectangle with colors for styling

**Naming:**
- Classes: PascalCase (TreeModel, TreeItem, Company)
- Functions: camelCase (getCompanyData, setupFromCompanyMap)
- Properties: camelCase (itemType, displayName)
- Slots/Signals: camelCase (idChanged, nameChanged)

**Error Handling:**
- Check pointer validity before dereferencing
- Validate model indices in data() method
- Return empty QVariant/QVariantMap for invalid states
